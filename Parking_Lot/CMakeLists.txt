cmake_minimum_required(VERSION 3.10)
project(ParkingLotSimulation CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES
    main.cpp
    models/Vehicle.cpp
    models/ParkingSpot.cpp
    models/Floor.cpp
    models/Ticket.cpp
    strategies/HourlyPricingStrategy.cpp
    services/ParkingLot.cpp
    gates/EntryGate.cpp
    gates/ExitGate.cpp
)

add_executable(parking_lot ${SOURCES})
