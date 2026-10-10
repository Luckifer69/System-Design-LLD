#include "ExitGate.h"
#include "../strategies/IPricingStrategy.h"
#include "../services/ParkingLot.h"
#include "../models/Ticket.h"
#include "../models/Vehicle.h"
#include "../models/ParkingSpot.h"
#include <iostream>
#include <ctime>

ExitGate::ExitGate(const std::string& id, std::shared_ptr<IPricingStrategy> strategy)
    : gateID(id), pricingStrategy(strategy) {}

bool ExitGate::exitVehicle(const std::string& ticketID) {
    std::cout << "\n[Exit Gate " << gateID << "] Processing Ticket: " << ticketID << "...\n";
    ParkingLot* lot = ParkingLot::getInstance();
    auto ticket = lot->getTicket(ticketID);

    if (!ticket) {
        std::cout << "  -> Error: Invalid or already processed ticket!\n";
        return false;
    }

    // 1. Calculate Fee
    double finalCost = pricingStrategy->calculateFee(ticket);
    ticket->closeTicket(time(nullptr), finalCost);

    // 2. Free up spot
    auto spot = ticket->getSpot();
    spot->removeVehicle();

    // 3. Mark Complete / Remove
    lot->removeActiveTicket(ticketID);

    std::cout << "  -> Total Fee: Rs. " << finalCost << "\n";
    std::cout << "  -> Success! Vehicle " << ticket->getVehicle()->getLicensePlate()
              << " exited. Floor " << spot->getFloorID() << ", Spot " << spot->getSpotID() << " is now free.\n";
    return true;
}
