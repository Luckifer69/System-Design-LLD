#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Passenger.h"
#include "../enums/Enums.h"

// Forward declaration
class Flight;

class Booking {
private:
    std::string bookingID;
    std::shared_ptr<Flight> flight;
    std::vector<Passenger> passengers;
    std::vector<std::string> seatNumbers;
    BookingStatus status;
    double totalAmount;

public:
    Booking(const std::string& bID,
            std::shared_ptr<Flight> f,
            const std::vector<Passenger>& pax,
            const std::vector<std::string>& seats,
            double amt);

    std::string getBookingID() const;
    std::shared_ptr<Flight> getFlight() const;
    std::vector<std::string> getSeatNumbers() const;
    BookingStatus getStatus() const;
    double getTotalAmount() const;

    void cancel();
    void printBooking() const;
};
