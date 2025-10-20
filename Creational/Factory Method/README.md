

# C++ Factory Method Pattern Implementation (Document Editor Example)

This repository contains a clear and concise implementation of the **Factory Method** design pattern in C++. The example is centered around a document management framework where different applications create different types of documents.

## Project Purpose

The primary goal of this project is to demonstrate the Factory Method pattern, a creational pattern that provides an interface for creating objects in a superclass but allows subclasses to alter the type of objects that will be created.

This pattern is essential when:
-   A class cannot anticipate the class of objects it must create.
-   A class wants its subclasses to specify the objects it creates.
-   You want to localize the logic for creating an object, promoting the **Open/Closed Principle**.

## Key Components of the Pattern

This implementation follows the classic structure of the Factory Method pattern:

1.  **Product (`Document`)**: An abstract interface for the objects the factory method creates. In this example, it's the base `Document` class.

2.  **Concrete Products (`TextDocument`, `SpreadsheetDocument`)**: Concrete classes that implement the `Product` interface.

3.  **Creator (`Application`)**: An abstract class that declares the factory method (`createDocument()`). This method's return type is the abstract `Product`. The `Creator` class contains core business logic that relies on `Product` objects but is decoupled from their concrete implementations.

4.  **Concrete Creators (`TextApplication`, `SpreadsheetApplication`)**: Subclasses that override the base factory method to produce a specific `ConcreteProduct`. The `TextApplication` creates a `TextDocument`, and the `SpreadsheetApplication` creates a `SpreadsheetDocument`.

## File Structure

For simplicity and ease of understanding, the class definitions are grouped into two main header files:

-   `Document.h`: Defines the `Document` abstract product and its concrete implementations (`TextDocument`, `SpreadsheetDocument`).
-   `Application.h`: Defines the `Application` abstract creator and its concrete implementations (`TextApplication`, `SpreadsheetApplication`).
-   `main.cpp`: The client code that demonstrates how to use different creator subclasses to get different products, all while interacting with the common `Application` interface.

## How to Compile and Run

Make sure you have a C++ compiler (e.g., g++) available. Open a terminal in the project's root directory and execute the following command.

**Compile:**
```bash
g++ -std=c++17 main.cpp -o factory_method_app
```

**Run:**
```bash
./factory_method_app
```


## Expected Output

The program's output demonstrates that the core logic in the `Application` class works seamlessly with different document types, thanks to the factory method delegating the instantiation logic to subclasses.

```
--- Testing with TextApplication ---
Application: Core logic is running.
TextApplication: Creating a TextDocument.
Opening Text Document...
Closing Text Document...

-------------------------------------

--- Testing with SpreadsheetApplication ---
Application: Core logic is running.
SpreadsheetApplication: Creating a SpreadsheetDocument.
Opening Spreadsheet Document...
Closing Spreadsheet Document...
```
