#include "Passenger.h"

Passenger::Passenger(const std::string& i, const std::string& n, const std::string& e)
    : id(i), name(n), email(e) {}

std::string Passenger::getId() const {
    return id;
}

std::string Passenger::getName() const {
    return name;
}

std::string Passenger::getEmail() const {
    return email;
}
