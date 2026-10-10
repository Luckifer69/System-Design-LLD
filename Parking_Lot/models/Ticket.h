#pragma once

#include <string>
#include <memory>
#include <ctime>
#include "../enums/Enums.h"

// Forward declarations
class Vehicle;
class ParkingSpot;

class Ticket {
private:
    std::string ticketID;
    std::shared_ptr<Vehicle> vehicle;
    std::shared_ptr<ParkingSpot> spot;
    time_t entryTime;
    time_t exitTime;
    double parkingFee;
    TicketStatus status;

public:
    Ticket(const std::string& tID, std::shared_ptr<Vehicle> v, std::shared_ptr<ParkingSpot> s);

    std::string getTicketID() const;
    std::shared_ptr<Vehicle> getVehicle() const;
    std::shared_ptr<ParkingSpot> getSpot() const;
    time_t getEntryTime() const;

    void closeTicket(time_t exit, double fee);
    void printTicket() const;
};
