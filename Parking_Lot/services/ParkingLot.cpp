#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot() {
    // Initialize 2 floors: 2 Bikes, 3 Cars, 1 Truck spot per floor
    floors.push_back(Floor(1, 2, 3, 1));
    floors.push_back(Floor(2, 2, 3, 1));
}

ParkingLot* ParkingLot::getInstance() {
    static ParkingLot instance;
    return &instance;
}

std::shared_ptr<ParkingSpot> ParkingLot::getAvailableSpot(VehicleType vType) {
    SpotType requiredType;
    if (vType == VehicleType::Bike) requiredType = SpotType::Bike;
    else if (vType == VehicleType::Car) requiredType = SpotType::Car;
    else if (vType == VehicleType::Truck) requiredType = SpotType::Truck;

    for (auto& floor : floors) {
        for (const auto& spot : floor.getSpots()) {
            if (spot->getIsFree() && spot->getType() == requiredType) {
                return spot;
            }
        }
    }
    return nullptr;
}

bool ParkingLot::isSpotAvailable(VehicleType vType) {
    return getAvailableSpot(vType) != nullptr;
}

void ParkingLot::addActiveTicket(std::shared_ptr<Ticket> t) {
    activeTickets[t->getTicketID()] = t;
}

std::shared_ptr<Ticket> ParkingLot::getTicket(const std::string& ticketID) {
    auto it = activeTickets.find(ticketID);
    if (it != activeTickets.end()) {
        return it->second;
    }
    return nullptr;
}

void ParkingLot::removeActiveTicket(const std::string& ticketID) {
    activeTickets.erase(ticketID);
}

void ParkingLot::displayParkingStatus() const {
    std::cout << "\n--- Current Parking Lot Status ---\n";
    for (const auto& floor : floors) {
        std::cout << "Floor " << floor.getFloorID() << ": ";
        int freeSpots = 0;
        for (const auto& spot : floor.getSpots()) {
            if (spot->getIsFree()) freeSpots++;
        }
        std::cout << freeSpots << "/" << floor.getSpots().size() << " spots available.\n";
    }
    std::cout << "----------------------------------\n";
}
