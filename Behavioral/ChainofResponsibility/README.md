# Chain of Responsibility - C++ Example

This project demonstrates the **Chain of Responsibility** design pattern using a Technical Support Help Desk scenario.

## Scenario
We have an IT support system with three levels of authority. When a request comes in, it is passed along a chain of handlers until one of them can solve it based on the issue's severity.

1.  **Level 1 Support**: Handles simple issues (Severity 1).
2.  **Level 2 Support**: Handles intermediate issues (Severity 2).
3.  **Manager**: Handles critical issues (Severity 3+).

The client (in `main.cpp`) simply sends the request to the first handler and does not need to know who specifically resolves it.

## Project Structure

*   **`SupportHandler` (Abstract Base Class)**: Defines the interface for handling requests and holds a pointer to the `nextHandler`.
*   **`Level1Support`**: Concrete handler. Checks if severity is 1. If not, passes to the next.
*   **`Level2Support`**: Concrete handler. Checks if severity is 2. If not, passes to the next.
*   **`Manager`**: Concrete handler. Handles high-severity issues (3 or higher).

