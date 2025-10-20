
# C++ Prototype Pattern Implementation (Shape Example)

This repository provides a practical and clear implementation of the **Prototype** design pattern in C++. The example is based on a graphical shape editor scenario, where new shapes are created by cloning pre-existing prototype instances.

## Project Purpose

The primary goal is to demonstrate how the Prototype pattern can be used to create new objects by copying an existing object, known as the "prototype." This approach is particularly useful when:

-   The cost of creating a new object from scratch is expensive (e.g., involves database queries, network requests, or complex computations).
-   The system needs to be independent of how its objects are created, composed, and represented.
-   You want to create objects whose specific types are determined at runtime.

The pattern allows a client to create a new object without being aware of its concrete class.

## Key Components of the Pattern

This implementation showcases the core participants of the Prototype pattern, along with a common helper class.

1.  **Abstract Prototype (`Shape`)**: An abstract base class that declares the cloning interface. The central part of this interface is the `clone()` method.

    ```cpp
    virtual std::unique_ptr<Shape> clone() const = 0;
    ```

2.  **Concrete Prototypes (`Circle`, `Rectangle`)**: Concrete classes that inherit from `Shape` and implement the `clone()` method. The implementation typically involves creating a new instance of the same class and passing the current object's state to it, often through a copy constructor.

    ```cpp
    // Inside the Circle class
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }
    ```

3.  **Prototype Manager (`PrototypeRegistry`)**: While not a formal part of the Gang of Four pattern, a registry or manager is a common and powerful addition.
    -   It acts as a centralized store for pre-configured prototype objects.
    -   It provides a convenient way for clients to retrieve and clone objects using a simple key (e.g., a string name), abstracting away the prototype instances themselves.

## File Structure

-   `Shape.h`: Defines the `Shape` abstract prototype and its concrete implementations (`Circle`, `Rectangle`). For simplicity, these are all in one header file.
-   `PrototypeRegistry.h`: Defines the manager class used to store, manage, and retrieve prototypes by name.
-   `main.cpp`: The client code. It demonstrates how to populate the registry with initial prototypes and then use it to create new shapes by cloning.

## How to Compile and Run

Ensure you have a modern C++ compiler (like g++). Since the implementation is mostly header-based, compiling is straightforward. Open a terminal in the project's root directory and run the following commands.

**Compile:**
```bash
g++ -std=c++17 main.cpp -o prototype_app
```

**Run:**
```bash
./prototype_app
```


## Expected Output

The program's output demonstrates that new, distinct objects are created by cloning the prototypes stored in the registry. The memory addresses confirm that the cloned objects are separate instances.

```
--- Creating new shapes by cloning prototypes ---

--- Verifying object instances ---
Address of original BigRedCircle prototype is not directly accessible here.
Address of cloned shape1 (Circle): 0x55d5e5e8a2a0
Address of cloned shape3 (Circle): 0x55d5e5e8a320
As expected, shape1 and shape3 are different objects.

--- Drawing all created shapes ---
Drawing a Red circle with radius 20.
Drawing a Blue rectangle of size 10x5.
Drawing a Red circle with radius 20.
```
