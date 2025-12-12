# State Design Pattern - C++ Example

This project demonstrates the **State Design Pattern** using a **Music Player** scenario.

## Scenario
A Music Player behaves differently depending on its current state.
*   If it is **Stopped** and you press Play, it starts playing.
*   If it is **Playing** and you press Play, nothing happens (or it pauses).
*   If it is **Playing** and you press Stop, it stops.

Instead of writing complex `if-else` or `switch` statements inside the MusicPlayer class to check the state, we delegate the behavior to separate State classes (`PlayingState`, `StoppedState`).

## Project Structure

1.  **`IState` (Interface)**: Defines methods for user actions (`pressPlay`, `pressStop`).
2.  **`MusicPlayer` (Context)**: Maintains a reference to the current `IState` object. It forwards user actions to the state object.
3.  **`StoppedState` & `PlayingState` (Concrete States)**:
    *   Implement the actual logic for each action.
    *   Handle state transitions (e.g., `StoppedState` switches the player to `PlayingState` when Play is pressed).
