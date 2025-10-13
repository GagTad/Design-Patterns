
---

# UniPay: A Universal Payment Gateway
A simple C++ project demonstrating the practical application of the **Adapter Design Pattern**.

## Overview

UniPay is a console-based C++ application that simulates an online shop's payment processing system. The core challenge is to integrate multiple, third-party payment providers (like PayPal and Stripe) into a single `OnlineShop` class, even though each provider has a completely different and incompatible API.

This project showcases how the Adapter pattern can solve this problem elegantly, resulting in a flexible, decoupled, and easily extensible system.

## The Problem: Incompatible Interfaces

Imagine you are building an e-commerce platform. You want to offer your customers multiple ways to pay.
-   **PayPal's API** might require a method call like `sendPayment(string username, double amount)`.
-   **Stripe's API** might use a different method like `makePayment(double total, string currency)`.

If you write your `OnlineShop` code to work directly with the PayPal API, it becomes tightly coupled. Adding Stripe later would require significant changes to the shop's logic, likely involving messy `if/else` statements. This code would be hard to maintain and even harder to extend with new payment providers in the future.

## The Solution: The Adapter Design Pattern

The **Adapter** pattern acts as a wrapper, or a "translator," that allows classes with incompatible interfaces to work together. It converts the interface of one class (the Adaptee) into an interface that the client expects (the Target).

### Pattern Components in UniPay

This project clearly demonstrates the four key roles of the Adapter pattern:

1.  **Target Interface (`IPaymentGateway.h`)**
    *   This is the unified interface that our `OnlineShop` (the Client) expects to work with.
    *   It defines a single, simple method: `virtual void processPayment(double amount) = 0;`.

2.  **Adaptees (`ThirdPartyAPIs.h`)**
    *   These are the existing third-party classes with their unique, incompatible interfaces. We cannot or do not want to modify their source code.
    *   `PayPalAPI`: Provides a `sendPayment(username, amount)` method.
    *   `StripeAPI`: Provides a `makePayment(amount, currency)` method.

3.  **Adapters (`PaymentAdapters.h`, `PaymentAdapters.cpp`)**
    *   These are the crucial "translator" classes that bridge the gap.
    *   `PayPalAdapter`: Implements the `IPaymentGateway` interface. Internally, it holds an instance of `PayPalAPI`. When its `processPayment` method is called, it translates that call into a call to `payPalApi->sendPayment(...)`.
    *   `StripeAdapter`: Also implements the `IPaymentGateway` interface but holds an instance of `StripeAPI`. It translates the `processPayment` call to `stripeApi->makePayment(...)`.

4.  **Client (`OnlineShop.h`, `OnlineShop.cpp`)**
    *   The `OnlineShop` is the client class that needs to process payments.
    *   It is only coupled to the `IPaymentGateway` interface. It has no knowledge of whether it's talking to PayPal, Stripe, or any other system. It simply calls the `processPayment` method on whatever gateway object it has been given.

## Project Structure

```
UniPay/
├── main.cpp                 # Entry point: sets up the shop and demonstrates different payment scenarios.
├── ThirdPartyAPIs.h         # Defines the incompatible Adaptee classes (PayPalAPI, StripeAPI).
├── IPaymentGateway.h        # Defines the Target interface our client expects.
├── PaymentAdapters.h        # Header file for the Adapter classes.
├── PaymentAdapters.cpp      # Implementation of the Adapter classes' translation logic.
├── OnlineShop.h             # Header for the Client class.
└── OnlineShop.cpp           # Implementation of the Client class.
```

## How to Build and Run

### Prerequisites
- A C++ compiler that supports C++17 (e.g., g++, Clang).

### Compilation
Navigate to the project directory in your terminal and run the following command:
```bash
g++ main.cpp OnlineShop.cpp PaymentAdapters.cpp -o UniPayApp -std=c++17
```

### Execution
Run the compiled application:
```bash
./UniPayApp
```

### Expected Output
```
=============================================
      Welcome to the UniPay Demo!      
=============================================

SCENARIO 1: Customer chooses to pay with PayPal.
--- Starting checkout process for order total: $150.75 ---
Adapter: Translating payment request for PayPal...
PayPal: Processing payment of $150.75 for user 'testuser@example.com'.
PayPal: Payment successful!
--- Checkout process finished. ---

SCENARIO 2: Customer decides to use Stripe instead.
--- Starting checkout process for order total: $49.99 ---
Adapter: Translating payment request for Stripe...
Stripe: Charging $49.99 in USD.
Stripe: Charge successful!
--- Checkout process finished. ---

SCENARIO 3: Trying to checkout without a payment gateway.
--- Starting checkout process for order total: $10 ---
ERROR: No payment gateway has been set for the shop!
--- Checkout process failed. ---
```

## Key Takeaways

This project demonstrates several important software design principles:
-   **Decoupling:** The `OnlineShop` (Client) is completely decoupled from the concrete payment provider implementations.
-   **Single Responsibility Principle (SRP):** Each adapter has only one responsibility: to translate requests for its specific adaptee.
-   **Open/Closed Principle (OCP):** The system is **open for extension** (we can add a new payment provider by creating a new adapter) but **closed for modification** (we don't need to change the existing `OnlineShop` code).
