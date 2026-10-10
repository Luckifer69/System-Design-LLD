#include "FlightSystem.h"
#include "PaymentGateway.h"
#include <iostream>

Mutex FlightSystem::systemMutex;

FlightSystem::FlightSystem() : bookingCounter(1000) {
    // Load initial catalog
    flights["FL-101"] = std::make_shared<Flight>("FL-101", "DEL", "BLR", "2026-10-15");
    flights["FL-202"] = std::make_shared<Flight>("FL-202", "BOM", "DEL", "2026-10-15");
}

FlightSystem* FlightSystem::getInstance() {
    static FlightSystem instance;
    return &instance;
}

std::vector<std::shared_ptr<Flight>> FlightSystem::searchFlights(const std::string& src,
                                                                 const std::string& dest,
                                                                 const std::string& date) {
    std::vector<std::shared_ptr<Flight>> result;
    for (const auto& pair : flights) {
        auto f = pair.second;
        if (f->getSource() == src && f->getDestination() == dest && f->getDate() == date) {
            result.push_back(f);
        }
    }
    return result;
}

std::shared_ptr<Booking> FlightSystem::createBooking(const std::string& flightID,
                                                    const std::vector<Passenger>& pax,
                                                    const std::vector<std::string>& seatNos) {
    if (flights.find(flightID) == flights.end()) {
        return nullptr;
    }

    auto flight = flights[flightID];
    std::string passengerName = pax.empty() ? "Guest" : pax[0].getName();
    std::cout << "\n[System] Attempting to book seats for " << passengerName << " on " << flightID << "...\n";

    // Step 1: Hold the seats (Concurrency handled inside Flight via granular lock)
    if (!flight->holdSeats(seatNos)) {
        std::cout << "  -> Booking Failed: One or more seats are already held/booked by another user.\n";
        return nullptr;
    }
    std::cout << "  -> Seats successfully HELD. Awaiting payment...\n";

    // Step 2: Process Payment (Mock calculating total as Rs. 2000 per seat for simplicity)
    double totalAmount = seatNos.size() * 2000.0;
    bool paymentSuccess = PaymentGateway::processPayment(passengerName, totalAmount);

    // Step 3: Confirm or Release
    if (paymentSuccess) {
        flight->confirmSeats(seatNos);

        std::string bID;
        {
            LockGuard<Mutex> lock(systemMutex);
            bID = "BKG-" + std::to_string(bookingCounter++);
        }

        auto booking = std::make_shared<Booking>(bID, flight, pax, seatNos, totalAmount);

        // Lock system map briefly to insert the booking record
        {
            LockGuard<Mutex> lock(systemMutex);
            bookings[bID] = booking;
        }

        std::cout << "  -> Booking CONFIRMED.\n";
        return booking;
    } else {
        flight->releaseSeats(seatNos);
        std::cout << "  -> Booking FAILED. Seats released back to Available pool.\n";
        return nullptr;
    }
}

bool FlightSystem::cancelBooking(const std::string& bookingID) {
    LockGuard<Mutex> lock(systemMutex);
    auto it = bookings.find(bookingID);
    if (it == bookings.end() || it->second->getStatus() != BookingStatus::Confirmed) {
        return false;
    }

    auto booking = it->second;
    booking->cancel();

    // Release seats back to the flight
    booking->getFlight()->releaseSeats(booking->getSeatNumbers());

    std::cout << "\n[System] Booking " << bookingID << " successfully cancelled. Seats released.\n";
    return true;
}
