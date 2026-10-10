#pragma once

#include "IPricingStrategy.h"
#include "../enums/Enums.h"
#include <map>

class HourlyPricingStrategy : public IPricingStrategy {
private:
    std::map<VehicleType, double> hourlyRates;

public:
    HourlyPricingStrategy();
    double calculateFee(std::shared_ptr<Ticket> ticket) override;
};
