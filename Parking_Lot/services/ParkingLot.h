#pragma once

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "../enums/Enums.h"
#include "../models/Floor.h"
#include "../models/Ticket.h"
#include "../models/ParkingSpot.h"

class ParkingLot {
private:
    std::vector<Floor> floors;
    std::map<std::string, std::shared_ptr<Ticket>> activeTickets;

    // Private constructor for Singleton pattern
    ParkingLot();

public:
    // Delete copy constructor and assignment operator
    ParkingLot(const ParkingLot&) = delete;
    ParkingLot& operator=(const ParkingLot&) = delete;

    // Thread-safe Meyers' Singleton
    static ParkingLot* getInstance();

    // Core Logic 1: Find Available Spot
    std::shared_ptr<ParkingSpot> getAvailableSpot(VehicleType vType);

    // Core Logic 2: Check Availability
    bool isSpotAvailable(VehicleType vType);

    void addActiveTicket(std::shared_ptr<Ticket> t);
    std::shared_ptr<Ticket> getTicket(const std::string& ticketID);
    void removeActiveTicket(const std::string& ticketID);
    void displayParkingStatus() const;
};
