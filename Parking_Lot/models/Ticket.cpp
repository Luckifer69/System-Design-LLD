#include "Ticket.h"
#include "Vehicle.h"
#include "ParkingSpot.h"
#include <iostream>

Ticket::Ticket(const std::string& tID, std::shared_ptr<Vehicle> v, std::shared_ptr<ParkingSpot> s)
    : ticketID(tID),
      vehicle(v),
      spot(s),
      entryTime(time(nullptr)),
      exitTime(0),
      parkingFee(0.0),
      status(TicketStatus::Active) {}

std::string Ticket::getTicketID() const {
    return ticketID;
}

std::shared_ptr<Vehicle> Ticket::getVehicle() const {
    return vehicle;
}

std::shared_ptr<ParkingSpot> Ticket::getSpot() const {
    return spot;
}

time_t Ticket::getEntryTime() const {
    return entryTime;
}

void Ticket::closeTicket(time_t exit, double fee) {
    exitTime = exit;
    parkingFee = fee;
    status = TicketStatus::Completed;
}

void Ticket::printTicket() const {
    std::cout << "------ TICKET [" << ticketID << "] ------\n"
              << "Vehicle: " << (vehicle ? vehicle->getLicensePlate() : "N/A") << "\n"
              << "Spot: " << (spot ? std::to_string(spot->getSpotID()) : "N/A")
              << " (Floor: " << (spot ? std::to_string(spot->getFloorID()) : "N/A") << ")\n"
              << "Status: " << (status == TicketStatus::Active ? "ACTIVE" : "COMPLETED") << "\n"
              << "---------------------------------\n";
}
