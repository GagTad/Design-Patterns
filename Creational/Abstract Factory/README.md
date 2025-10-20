
# C++ Abstract Factory Pattern Implementation (GUI Factory Example)

This repository provides a comprehensive implementation of the **Abstract Factory** design pattern in C++. The example demonstrates how to create families of related objects (GUI widgets for different operating systems) without specifying their concrete classes.

## Project Purpose

The primary goal of this project is to illustrate the Abstract Factory pattern. This pattern provides an interface for creating **families of related or dependent objects** without specifying their concrete classes. Think of it as a "factory for factories."

This pattern is particularly useful when:
-   A system needs to be independent of how its products are created, composed, and represented.
-   A system must be configured with one of multiple families of products.
-   You want to enforce that products from the same family are always used together, preventing mismatches (e.g., using a Windows button with a macOS checkbox).

## Key Components of the Pattern

This implementation showcases all the classic participants of the Abstract Factory pattern:

1.  **Abstract Factory (`IGUIFactory`)**: The main interface that declares a set of methods for creating abstract products. Each method corresponds to one product type (e.g., `createButton()`, `createCheckbox()`).

2.  **Concrete Factories (`WinFactory`, `MacFactory`)**: Classes that implement the `IGUIFactory` interface. Each concrete factory is responsible for creating a specific family of products. For instance, `WinFactory` creates Windows-style widgets, while `MacFactory` creates macOS-style widgets.

3.  **Abstract Products (`IButton`, `ICheckbox`)**: The interfaces for a single type of product within a family. These define the common operations that all concrete products of that type must implement.

4.  **Concrete Products (`WinButton`, `WinCheckbox`, `MacButton`, `MacCheckbox`)**: The concrete implementations of the abstract products, grouped into families. These are the actual objects created by the concrete factories.

5.  **Client (`Application`)**: The class that uses the factory and product interfaces. The client code is completely decoupled from the concrete implementations; it works only with abstract types like `IGUIFactory`, `IButton`, and `ICheckbox`.

## File Structure

The project is organized into multiple files to reflect a clean, modular design:

-   `IWidget.h`: Defines the abstract product interfaces (`IButton`, `ICheckbox`).
-   `WindowsWidget.h`: Defines the concrete product family for Windows (`WinButton`, `WinCheckbox`).
-   `MacWidget.h`: Defines the concrete product family for macOS (`MacButton`, `MacCheckbox`).
-   `IGUIFactory.h`: Defines the abstract factory interface.
-   `WinFactory.h`: Defines the concrete factory for the Windows family.
-   `MacFactory.h`: Defines the concrete factory for the macOS family.
-   `Application.h` / `Application.cpp`: The client class that uses a factory to build its UI.
-   `main.cpp`: The application entry point, where the appropriate concrete factory is chosen and passed to the client.

## How to Compile and Run

Make sure you have a C++ compiler (e.g., g++) that supports the C++17 standard. Open a terminal in the project's root directory and execute the following commands.

**Compile:**
```bash
g++ -std=c++17 main.cpp Application.cpp -o abstract_factory_app
```

**Run:**
```bash
./abstract_factory_app
```


## Expected Output

The program's output demonstrates how the client (`Application`) can create a complete UI for different operating systems simply by being configured with a different factory. The core client logic remains unchanged.

```
Client: Application is configured to run on Windows
Application: Creating UI elements using the provided factory.
Painting a Windows button.
Painting a Windows checkbox.

Client: Re-configuring application to run on macOS
Application: Creating UI elements using the provided factory.
Painting a macOS button.
Painting a macOS checkbox.
```
