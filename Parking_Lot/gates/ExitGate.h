#pragma once

#include <string>
#include <memory>

// Forward declaration
class IPricingStrategy;

class ExitGate {
private:
    std::string gateID;
    std::shared_ptr<IPricingStrategy> pricingStrategy;

public:
    ExitGate(const std::string& id, std::shared_ptr<IPricingStrategy> strategy);
    bool exitVehicle(const std::string& ticketID);
};
