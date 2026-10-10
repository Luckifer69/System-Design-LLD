#include "PaymentGateway.h"
#include <iostream>
#include <cstdlib>

bool PaymentGateway::processPayment(const std::string& userId, double amount) {
    (void)userId;
    std::cout << "  [Payment] Processing Rs." << amount << "...\n";
    // Simulating a 90% success rate
    bool success = (rand() % 10) > 0;
    if (success) {
        std::cout << "  [Payment] SUCCESS.\n";
    } else {
        std::cout << "  [Payment] FAILED. Rollback initiated.\n";
    }
    return success;
}
