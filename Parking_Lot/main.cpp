#include <iostream>
#include <memory>
#include "enums/Enums.h"
#include "models/Vehicle.h"
#include "models/ParkingSpot.h"
#include "models/Floor.h"
#include "models/Ticket.h"
#include "strategies/HourlyPricingStrategy.h"
#include "services/ParkingLot.h"
#include "gates/EntryGate.h"
#include "gates/ExitGate.h"

int main() {
    std::cout << "--- Starting CRED Parking Lot Simulation ---\n";

    ParkingLot* myLot = ParkingLot::getInstance();
    myLot->displayParkingStatus();

    EntryGate entryGate1("ENT_1");
    EntryGate entryGate2("ENT_2");

    // Inject Strategy Pattern Dependency
    auto hourlyPricing = std::make_shared<HourlyPricingStrategy>();
    ExitGate exitGate1("EXT_1", hourlyPricing);

    // Create Vehicles
    auto car1 = std::make_shared<Car>("JH-01-AB-1234");
    auto car2 = std::make_shared<Car>("WB-02-XY-9876");
    auto truck1 = std::make_shared<Truck>("MH-12-TRK-99");
    auto bike1 = std::make_shared<Bike>("KA-05-BK-1111");

    // Park Vehicles
    auto t1 = entryGate1.parkVehicle(car1);
    auto t2 = entryGate2.parkVehicle(car2);
    auto t3 = entryGate1.parkVehicle(truck1);
    auto t4 = entryGate2.parkVehicle(bike1);

    myLot->displayParkingStatus();

    // Exit Vehicles
    if (t1) {
        exitGate1.exitVehicle(t1->getTicketID());
    }

    // Attempting to park a new car now that a spot is freed
    auto car3 = std::make_shared<Car>("DL-10-ZZ-0000");
    auto t5 = entryGate1.parkVehicle(car3);

    myLot->displayParkingStatus();

    std::cout << "\n--- Simulation Complete ---\n";
    return 0;
}
