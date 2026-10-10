#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Seat.h"
#include "../concurrency/Concurrency.h"

class Flight {
private:
    std::string flightID;
    std::string source;
    std::string destination;
    std::string date; // Format: YYYY-MM-DD
    std::map<std::string, std::shared_ptr<Seat>> seats;
    Mutex flightMutex; // Granular lock: protects seat state transitions for this specific flight

public:
    Flight(const std::string& fID, const std::string& src, const std::string& dest, const std::string& d);

    std::string getFlightID() const;
    std::string getSource() const;
    std::string getDestination() const;
    std::string getDate() const;

    // Read operation (Thread-safe)
    void displayAvailableSeats();

    // Two-Phase Commit Step 1: Hold (Thread-safe)
    bool holdSeats(const std::vector<std::string>& seatNumbers);

    // Two-Phase Commit Step 2a: Confirm (Thread-safe)
    void confirmSeats(const std::vector<std::string>& seatNumbers);

    // Two-Phase Commit Step 2b: Release/Cancel (Thread-safe)
    void releaseSeats(const std::vector<std::string>& seatNumbers);
};
