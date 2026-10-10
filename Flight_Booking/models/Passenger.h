#pragma once

#include <string>

class Passenger {
private:
    std::string id;
    std::string name;
    std::string email;

public:
    Passenger(const std::string& i, const std::string& n, const std::string& e);

    std::string getId() const;
    std::string getName() const;
    std::string getEmail() const;
};
