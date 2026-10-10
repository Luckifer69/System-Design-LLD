#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "enums/Enums.h"
#include "concurrency/Concurrency.h"
#include "models/Passenger.h"
#include "models/Seat.h"
#include "models/Flight.h"
#include "models/Booking.h"
#include "services/FlightSystem.h"

void userSimulation(std::string userName, std::string flightID, std::vector<std::string> seatNos) {
    FlightSystem* system = FlightSystem::getInstance();
    Passenger p(userName, userName, userName + "@email.com");

    auto booking = system->createBooking(flightID, {p}, seatNos);
    if (booking) {
        booking->printBooking();
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for payment mock
    std::cout << "--- Starting CRED Flight Booking System ---\n";

    FlightSystem* system = FlightSystem::getInstance();

    // Search
    auto availableFlights = system->searchFlights("DEL", "BLR", "2026-10-15");
    if (!availableFlights.empty()) {
        std::cout << "Found Flight: " << availableFlights[0]->getFlightID() << "\n";
        availableFlights[0]->displayAvailableSeats();
    }

    // Simulate Concurrency: Two users trying to book the same seat at the exact same time
    std::cout << "\n--- Simulating Concurrent Booking Attempt on Seat 1A ---\n";
    Thread t1(userSimulation, "Divyanshu", "FL-101", std::vector<std::string>{"1A"});
    Thread t2(userSimulation, "Aditya", "FL-101", std::vector<std::string>{"1A", "1B"});

    t1.join();
    t2.join();

    // Check final seat status
    std::cout << "\n--- Final Seat Availability ---\n";
    availableFlights[0]->displayAvailableSeats();

    return 0;
}
