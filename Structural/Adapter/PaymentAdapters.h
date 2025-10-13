#pragma once
#include "IPaymentGateway.h" 
#include "ThirdPartyAPIs.h"   
#include <memory>             

class PayPalAdapter : public IPaymentGateway {
private:
    std::unique_ptr<PayPalAPI> m_payPalApi;
    std::string m_username; 

public:

    PayPalAdapter(const std::string& username);


    void processPayment(double amount) override;
};


class StripeAdapter : public IPaymentGateway {
private:
    std::unique_ptr<StripeAPI> m_stripeApi;
    std::string m_currency; 

public:

    StripeAdapter(const std::string& currency = "USD");

    void processPayment(double amount) override;
};
