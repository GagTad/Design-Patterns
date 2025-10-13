#pragma once


class IPaymentGateway {
public:
   
    virtual void processPayment(double amount) = 0;

    virtual ~IPaymentGateway() {}
};