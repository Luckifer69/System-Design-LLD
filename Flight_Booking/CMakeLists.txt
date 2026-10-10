cmake_minimum_required(VERSION 3.10)
project(FlightBookingSystem CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES
    main.cpp
    models/Passenger.cpp
    models/Seat.cpp
    models/Flight.cpp
    models/Booking.cpp
    services/PaymentGateway.cpp
    services/FlightSystem.cpp
)

add_executable(flight_booking ${SOURCES})

find_package(Threads)
if(Threads_FOUND)
    target_link_libraries(flight_booking Threads::Threads)
endif()
