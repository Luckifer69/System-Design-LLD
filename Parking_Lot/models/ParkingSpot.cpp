#include "ParkingSpot.h"
#include "Vehicle.h"

ParkingSpot::ParkingSpot(int sID, int fID, SpotType t)
    : spotID(sID), floorID(fID), type(t), isFree(true), currentVehicle(nullptr) {}

int ParkingSpot::getSpotID() const {
    return spotID;
}

int ParkingSpot::getFloorID() const {
    return floorID;
}

SpotType ParkingSpot::getType() const {
    return type;
}

bool ParkingSpot::getIsFree() const {
    return isFree;
}

void ParkingSpot::assignVehicle(std::shared_ptr<Vehicle> v) {
    currentVehicle = v;
    isFree = false;
}

void ParkingSpot::removeVehicle() {
    currentVehicle = nullptr;
    isFree = true;
}
