#include "Flight.h"
#include <iostream>

Flight::Flight(const std::string& fID, const std::string& src, const std::string& dest, const std::string& d)
    : flightID(fID), source(src), destination(dest), date(d) {
    // Initialize dummy seats
    seats["1A"] = std::make_shared<Seat>("1A", SeatClass::Business, 5000.0);
    seats["1B"] = std::make_shared<Seat>("1B", SeatClass::Business, 5000.0);
    seats["2A"] = std::make_shared<Seat>("2A", SeatClass::Economy, 2000.0);
    seats["2B"] = std::make_shared<Seat>("2B", SeatClass::Economy, 2000.0);
}

std::string Flight::getFlightID() const {
    return flightID;
}

std::string Flight::getSource() const {
    return source;
}

std::string Flight::getDestination() const {
    return destination;
}

std::string Flight::getDate() const {
    return date;
}

void Flight::displayAvailableSeats() {
    LockGuard<Mutex> lock(flightMutex);
    std::cout << "Available Seats for Flight " << flightID << ": ";
    for (const auto& pair : seats) {
        if (pair.second->getStatus() == SeatStatus::Available) {
            std::cout << pair.first << " ";
        }
    }
    std::cout << "\n";
}

bool Flight::holdSeats(const std::vector<std::string>& seatNumbers) {
    LockGuard<Mutex> lock(flightMutex);

    // 1. Check availability for ALL requested seats to prevent partial booking
    for (const std::string& seatNo : seatNumbers) {
        auto it = seats.find(seatNo);
        if (it == seats.end() || it->second->getStatus() != SeatStatus::Available) {
            return false;
        }
    }

    // 2. Mark as Held
    for (const std::string& seatNo : seatNumbers) {
        seats[seatNo]->setStatus(SeatStatus::Held);
    }
    return true;
}

void Flight::confirmSeats(const std::vector<std::string>& seatNumbers) {
    LockGuard<Mutex> lock(flightMutex);
    for (const std::string& seatNo : seatNumbers) {
        auto it = seats.find(seatNo);
        if (it != seats.end()) {
            it->second->setStatus(SeatStatus::Booked);
        }
    }
}

void Flight::releaseSeats(const std::vector<std::string>& seatNumbers) {
    LockGuard<Mutex> lock(flightMutex);
    for (const std::string& seatNo : seatNumbers) {
        auto it = seats.find(seatNo);
        if (it != seats.end()) {
            it->second->setStatus(SeatStatus::Available);
        }
    }
}
