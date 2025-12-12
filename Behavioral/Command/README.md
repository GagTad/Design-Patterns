# Command Design Pattern - C++ Example

This project demonstrates the **Command Design Pattern** using a simple **Smart Home Remote Control** scenario.

## Scenario
We want to decouple the object that invokes the operation (the Remote Control) from the object that knows how to perform it (the Light).
Instead of the remote calling `light->turnOn()` directly, we encapsulate the request as a `LightOnCommand` object. This allows us to easily swap commands and, most importantly, perform **Undo** operations.

## Project Structure

1.  **`ICommand` (Interface)**: Declares the `execute()` and `undo()` methods.
2.  **`Light` (Receiver)**: The actual device that performs the work (`turnOn`, `turnOff`).
3.  **`LightOnCommand` / `LightOffCommand` (Concrete Commands)**: Classes that implement `ICommand`. They hold a pointer to `Light` and bind the `execute()` method to the appropriate action on the light.
4.  **`RemoteControl` (Invoker)**: It holds a command object and asks it to execute the request when the button is pressed. It doesn't know details about the Light class.
