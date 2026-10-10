#include "Floor.h"

Floor::Floor(int id, int bikeSpots, int carSpots, int truckSpots)
    : floorID(id) {
    int spotCounter = 1;
    for (int i = 0; i < bikeSpots; ++i) {
        spots.push_back(std::make_shared<ParkingSpot>(spotCounter++, floorID, SpotType::Bike));
    }
    for (int i = 0; i < carSpots; ++i) {
        spots.push_back(std::make_shared<ParkingSpot>(spotCounter++, floorID, SpotType::Car));
    }
    for (int i = 0; i < truckSpots; ++i) {
        spots.push_back(std::make_shared<ParkingSpot>(spotCounter++, floorID, SpotType::Truck));
    }
}

int Floor::getFloorID() const {
    return floorID;
}

const std::vector<std::shared_ptr<ParkingSpot>>& Floor::getSpots() const {
    return spots;
}
