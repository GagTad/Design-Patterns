#pragma once


#include <iostream>
#include <string>


class PayPalAPI {
public:
    
    void sendPayment(const std::string& username, double amount) {
        std::cout << "PayPal: Processing payment of $" << amount << " for user '" << username << "'." << std::endl;
        std::cout << "PayPal: Payment successful!" << std::endl;
    }
};

class StripeAPI {
public:
    
    void makePayment(double amount, const std::string& currency) {
        std::cout << "Stripe: Charging $" << amount << " in " << currency << "." << std::endl;
        std::cout << "Stripe: Charge successful!" << std::endl;
    }
};