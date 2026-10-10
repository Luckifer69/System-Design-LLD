#pragma once

#include <memory>

// Forward declaration
class Ticket;

class IPricingStrategy {
public:
    virtual ~IPricingStrategy() = default;
    virtual double calculateFee(std::shared_ptr<Ticket> ticket) = 0;
};
