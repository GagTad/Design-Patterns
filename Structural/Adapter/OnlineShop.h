#pragma once
#include "IPaymentGateway.h"
#include <memory>

class OnlineShop {
private:
   
    std::unique_ptr<IPaymentGateway> m_paymentGateway;

public:
    
    void setPaymentGateway(std::unique_ptr<IPaymentGateway> gateway);
    void checkout(double orderTotal);
};
