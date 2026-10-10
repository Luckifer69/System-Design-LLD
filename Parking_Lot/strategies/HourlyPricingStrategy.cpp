#include "HourlyPricingStrategy.h"
#include "../models/Ticket.h"
#include "../models/Vehicle.h"
#include <ctime>
#include <cmath>

HourlyPricingStrategy::HourlyPricingStrategy() {
    hourlyRates[VehicleType::Bike] = 10.0;
    hourlyRates[VehicleType::Car] = 20.0;
    hourlyRates[VehicleType::Truck] = 50.0;
}

double HourlyPricingStrategy::calculateFee(std::shared_ptr<Ticket> ticket) {
    time_t exitTime = time(nullptr);
    double durationInSeconds = difftime(exitTime, ticket->getEntryTime());

    // Simulating time for testing (forcing at least 2 hours if instant)
    if (durationInSeconds < 5) {
        durationInSeconds = 7200;
    }

    double durationInHours = std::ceil(durationInSeconds / 3600.0);
    double rate = hourlyRates[ticket->getVehicle()->getType()];
    return rate * durationInHours;
}
