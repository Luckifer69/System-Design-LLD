#include "Booking.h"
#include "Flight.h"
#include <iostream>

Booking::Booking(const std::string& bID,
                 std::shared_ptr<Flight> f,
                 const std::vector<Passenger>& pax,
                 const std::vector<std::string>& seats,
                 double amt)
    : bookingID(bID),
      flight(f),
      passengers(pax),
      seatNumbers(seats),
      status(BookingStatus::Confirmed),
      totalAmount(amt) {}

std::string Booking::getBookingID() const {
    return bookingID;
}

std::shared_ptr<Flight> Booking::getFlight() const {
    return flight;
}

std::vector<std::string> Booking::getSeatNumbers() const {
    return seatNumbers;
}

BookingStatus Booking::getStatus() const {
    return status;
}

double Booking::getTotalAmount() const {
    return totalAmount;
}

void Booking::cancel() {
    status = BookingStatus::Cancelled;
}

void Booking::printBooking() const {
    std::cout << "------ TICKET [" << bookingID << "] ------\n"
              << "Flight: " << (flight ? flight->getFlightID() : "N/A")
              << " | " << (flight ? flight->getSource() : "N/A")
              << " -> " << (flight ? flight->getDestination() : "N/A") << "\n"
              << "Status: " << (status == BookingStatus::Confirmed ? "CONFIRMED" : "CANCELLED") << "\n"
              << "Passengers: " << passengers.size() << " | Seats: ";
    for (const auto& s : seatNumbers) {
        std::cout << s << " ";
    }
    std::cout << "\nTotal Paid: Rs." << totalAmount << "\n--------------------------------\n";
}
