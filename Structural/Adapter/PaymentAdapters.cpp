#include "PaymentAdapters.h"


PayPalAdapter::PayPalAdapter(const std::string& username)
    : m_username(username) {
    m_payPalApi = std::make_unique<PayPalAPI>();
}

void PayPalAdapter::processPayment(double amount) {
    std::cout << "Adapter: Translating payment request for PayPal..." << std::endl;
    m_payPalApi->sendPayment(m_username, amount);
}

StripeAdapter::StripeAdapter(const std::string& currency)
    : m_currency(currency) {
    m_stripeApi = std::make_unique<StripeAPI>();
}

void StripeAdapter::processPayment(double amount) {
    std::cout << "Adapter: Translating payment request for Stripe..." << std::endl;
    m_stripeApi->makePayment(amount, m_currency);
}