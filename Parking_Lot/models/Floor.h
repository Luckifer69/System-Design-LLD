#pragma once

#include <vector>
#include <memory>
#include "ParkingSpot.h"

class Floor {
private:
    int floorID;
    std::vector<std::shared_ptr<ParkingSpot>> spots;

public:
    Floor(int id, int bikeSpots, int carSpots, int truckSpots);

    int getFloorID() const;
    const std::vector<std::shared_ptr<ParkingSpot>>& getSpots() const;
};
