#include "OnlineShop.h"
#include <iostream>
#include <utility> 

void OnlineShop::setPaymentGateway(std::unique_ptr<IPaymentGateway> gateway) {

    m_paymentGateway = std::move(gateway);
}

void OnlineShop::checkout(double orderTotal) {
    std::cout << "--- Starting checkout process for order total: $" << orderTotal << " ---" << std::endl;

    if (m_paymentGateway) {
        m_paymentGateway->processPayment(orderTotal);
        std::cout << "--- Checkout process finished. ---" << std::endl << std::endl;
    }
    else {
        std::cerr << "ERROR: No payment gateway has been set for the shop!" << std::endl;
        std::cout << "--- Checkout process failed. ---" << std::endl << std::endl;
    }
}