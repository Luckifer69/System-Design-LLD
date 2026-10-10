#pragma once

#include <memory>
#include "../enums/Enums.h"

// Forward declaration
class Vehicle;

class ParkingSpot {
private:
    int spotID;
    int floorID;
    SpotType type;
    bool isFree;
    std::shared_ptr<Vehicle> currentVehicle;

public:
    ParkingSpot(int sID, int fID, SpotType t);

    int getSpotID() const;
    int getFloorID() const;
    SpotType getType() const;
    bool getIsFree() const;

    void assignVehicle(std::shared_ptr<Vehicle> v);
    void removeVehicle();
};
