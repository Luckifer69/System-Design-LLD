#pragma once

#include <string>
#include "../enums/Enums.h"

class Vehicle {
protected:
    std::string licensePlate;
    VehicleType type;

public:
    Vehicle(const std::string& plate, VehicleType t);
    virtual ~Vehicle() = default;

    std::string getLicensePlate() const;
    VehicleType getType() const;
};

class Bike : public Vehicle {
public:
    explicit Bike(const std::string& plate);
};

class Car : public Vehicle {
public:
    explicit Car(const std::string& plate);
};

class Truck : public Vehicle {
public:
    explicit Truck(const std::string& plate);
};
