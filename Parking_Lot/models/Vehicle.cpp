#include "Vehicle.h"

Vehicle::Vehicle(const std::string& plate, VehicleType t)
    : licensePlate(plate), type(t) {}

std::string Vehicle::getLicensePlate() const {
    return licensePlate;
}

VehicleType Vehicle::getType() const {
    return type;
}

Bike::Bike(const std::string& plate)
    : Vehicle(plate, VehicleType::Bike) {}

Car::Car(const std::string& plate)
    : Vehicle(plate, VehicleType::Car) {}

Truck::Truck(const std::string& plate)
    : Vehicle(plate, VehicleType::Truck) {}
