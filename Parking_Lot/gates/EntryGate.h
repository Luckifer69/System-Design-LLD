#pragma once

#include <string>
#include <memory>

// Forward declarations
class Vehicle;
class Ticket;

class EntryGate {
private:
    std::string gateID;

public:
    explicit EntryGate(const std::string& id);
    std::shared_ptr<Ticket> parkVehicle(std::shared_ptr<Vehicle> vehicle);
};
