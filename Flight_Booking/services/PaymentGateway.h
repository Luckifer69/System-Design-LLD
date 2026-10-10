#pragma once

#include <string>

class PaymentGateway {
public:
    static bool processPayment(const std::string& userId, double amount);
};
