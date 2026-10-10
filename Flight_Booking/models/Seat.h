#pragma once

#include <string>
#include "../enums/Enums.h"

class Seat {
private:
    std::string seatNumber;
    SeatClass seatClass;
    SeatStatus status;
    double price;

public:
    Seat(const std::string& seatNo, SeatClass sClass, double p);

    std::string getSeatNumber() const;
    SeatClass getSeatClass() const;
    double getPrice() const;
    SeatStatus getStatus() const;

    void setStatus(SeatStatus s);
};
