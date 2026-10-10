#include "Seat.h"

Seat::Seat(const std::string& seatNo, SeatClass sClass, double p)
    : seatNumber(seatNo), seatClass(sClass), status(SeatStatus::Available), price(p) {}

std::string Seat::getSeatNumber() const {
    return seatNumber;
}

SeatClass Seat::getSeatClass() const {
    return seatClass;
}

double Seat::getPrice() const {
    return price;
}

SeatStatus Seat::getStatus() const {
    return status;
}

void Seat::setStatus(SeatStatus s) {
    status = s;
}
