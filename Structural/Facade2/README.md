# Facade Design Pattern - C++ Example

This project demonstrates the **Facade Design Pattern** using a **Home Theater System** scenario.

## Scenario
A modern home theater system consists of multiple complex components: TV, Sound System, Lights, Streaming Players, etc.
To perform a simple action like "Watch a Movie", a user normally has to interact with all these devices separately.
The **Facade** pattern provides a simplified interface (a single class) that handles all these interactions behind the scenes.

## Project Structure

1.  **`Subsystems` (TV, SoundSystem, RoomLights)**:
    *   These are the complex classes with many specific methods (`turnOn`, `setVolume`, `dim`, `setInput`).
    *   In a real-world scenario, these might be 3rd-party libraries or complex driver code.

2.  **`HomeTheaterFacade` (The Facade)**:
    *   This class sits between the Client and the Subsystems.
    *   It wraps the complex sequence of operations into simple methods like `watchMovie()` and `endMovie()`.

3.  **`main.cpp` (The Client)**:
    *   The client code is clean and simple. It doesn't need to know the order in which to turn on the devices; it just calls the Facade.


