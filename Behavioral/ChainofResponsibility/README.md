Project Structure
SupportHandler (Abstract Base Class): Defines the interface for handling requests and holds a pointer to the nextHandler.
Level1Support: Concrete handler. Checks if severity is 1. If not, passes to the next.
Level2Support: Concrete handler. Checks if severity is 2. If not, passes to the next.
Manager: Concrete handler. Handles high-severity issues (3 or higher).
