

# C++ Builder Pattern Implementation (Computer Example)

This repository provides a clear and practical implementation of the **Builder** design pattern in C++. The example scenario involves constructing complex `Computer` objects with multiple optional and required components.

## Project Purpose

The main goal of this project is to demonstrate how the Builder pattern simplifies the creation of complex objects. It addresses common problems like the "Telescoping Constructor" anti-pattern (constructors with too many parameters) and makes the object creation process more readable and maintainable.

The pattern separates the construction of a complex object from its representation, allowing the same construction process to create different representations.

## Key Components of the Pattern

This implementation follows the classic structure of the Builder pattern:

1.  **Product (`Computer`)**: The complex object we want to create. Its constructor is made `private` so that it can only be instantiated by its `friend`, the `ComputerBuilder`. This ensures that objects are always created in a valid state.

2.  **Builder (`ComputerBuilder`)**: An interface for creating the parts of the `Product`.
    -   It maintains an instance of the `Computer` it is building.
    -   It provides methods (`setCPU`, `setRAM`, etc.) to configure the product's parts.
    -   These methods support **method chaining** (e.g., `builder.setCPU(...).setRAM(...)`) for a fluent and readable API.
    -   The final `build()` method returns the fully constructed object, transferring ownership via `std::unique_ptr`.

3.  **Director (`ComputerDirector`)**: An optional class that encapsulates common construction logic.
    -   The `Director` knows the specific sequence of steps required to build standard configurations (e.g., a "Gaming PC" or an "Office PC").
    -   It works with any `Builder` instance passed to it, decoupling the client from the specific steps of construction.

## File Structure

-   `Computer.h`: Defines the `Computer` class (the Product).
-   `ComputerBuilder.h` / `ComputerBuilder.cpp`: Defines and implements the `ComputerBuilder` class (the Builder).
-   `ComputerDirector.h` / `ComputerDirector.cpp`: Defines and implements the `ComputerDirector` class (the Director).
-   `main.cpp`: The client code that demonstrates three usage scenarios:
     1.  Using the `Director` to build a standard "Gaming PC".
     2.  Using the `Director` to build a standard "Office PC".
     3.  Using the `Builder` directly to create a custom PC configuration.

## How to Compile and Run

Make sure you have a C++ compiler (e.g., g++) available. Open a terminal in the project's root directory and execute the following commands.

**Compile:**
```bash
g++ main.cpp ComputerBuilder.cpp ComputerDirector.cpp -o computer_builder_app
```

**Run:**
```bash
./computer_builder_app
```


## Expected Output

Running the application will produce the following output, showcasing the different computer configurations created by the builder.

```
--- Using Director to build a Gaming PC ---
Computer Configuration:
  CPU: Intel Core i9
  RAM: 32GB DDR5
  Storage: 2TB NVMe SSD
  GPU: NVIDIA RTX 4090
-------------------------
--- Using Director to build an Office PC ---
Computer Configuration:
  CPU: Intel Core i5
  RAM: 16GB DDR4
  Storage: 512GB SATA SSD
  GPU: Integrated
-------------------------
--- Using Builder directly for a custom PC ---
Computer Configuration:
  CPU: AMD Ryzen 5
  RAM: 16GB DDR4
  Storage: 1TB NVMe SSD
  GPU: Integrated
-------------------------
```
