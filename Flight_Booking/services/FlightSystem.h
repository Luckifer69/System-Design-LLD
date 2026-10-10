#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "../models/Flight.h"
#include "../models/Booking.h"
#include "../models/Passenger.h"
#include "../concurrency/Concurrency.h"

class FlightSystem {
private:
    static Mutex systemMutex;

    std::map<std::string, std::shared_ptr<Flight>> flights;
    std::map<std::string, std::shared_ptr<Booking>> bookings;
    int bookingCounter;

    // Private constructor for Singleton
    FlightSystem();

public:
    FlightSystem(const FlightSystem&) = delete;
    FlightSystem& operator=(const FlightSystem&) = delete;

    // Thread-safe Singleton
    static FlightSystem* getInstance();

    // 1. Search Flights
    std::vector<std::shared_ptr<Flight>> searchFlights(const std::string& src,
                                                       const std::string& dest,
                                                       const std::string& date);

    // 2. Core Booking Workflow (Two-Phase Commit: Hold -> Pay -> Confirm/Rollback)
    std::shared_ptr<Booking> createBooking(const std::string& flightID,
                                          const std::vector<Passenger>& pax,
                                          const std::vector<std::string>& seatNos);

    // 3. Cancel Booking
    bool cancelBooking(const std::string& bookingID);
};
