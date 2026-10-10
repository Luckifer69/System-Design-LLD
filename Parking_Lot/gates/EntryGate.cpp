#include "EntryGate.h"
#include "../models/Vehicle.h"
#include "../models/Ticket.h"
#include "../models/ParkingSpot.h"
#include "../services/ParkingLot.h"
#include <iostream>

EntryGate::EntryGate(const std::string& id) : gateID(id) {}

std::shared_ptr<Ticket> EntryGate::parkVehicle(std::shared_ptr<Vehicle> vehicle) {
    std::cout << "\n[Gate " << gateID << "] Vehicle " << vehicle->getLicensePlate() << " arriving...\n";
    ParkingLot* lot = ParkingLot::getInstance();

    auto spot = lot->getAvailableSpot(vehicle->getType());
    if (!spot) {
        std::cout << "  -> Error: Parking Lot is full for this Vehicle Type.\n";
        return nullptr;
    }

    spot->assignVehicle(vehicle);
    std::string ticketID = "TKT-" + gateID + "-" + std::to_string(spot->getFloorID()) + "-" + std::to_string(spot->getSpotID());
    auto ticket = std::make_shared<Ticket>(ticketID, vehicle, spot);

    lot->addActiveTicket(ticket);
    std::cout << "  -> Success! Assigned Floor " << spot->getFloorID() << ", Spot " << spot->getSpotID() << ".\n";
    ticket->printTicket();
    return ticket;
}
