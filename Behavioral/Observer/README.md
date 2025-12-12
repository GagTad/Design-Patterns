# Observer Design Pattern - C++ Example

This project demonstrates the **Observer Design Pattern** using a **YouTube Channel Subscription** scenario.

## Scenario
In this system, we have a "One-to-Many" dependency.
1.  **The Subject (YouTube Channel):** Holds the state (the latest video). When it uploads a video, it must notify everyone listening to it.
2.  **The Observers (Subscribers):** Users who want to be notified when the channel state changes.

This allows the Channel to send updates without knowing exactly who the subscribers are or how they handle the notification.

## Project Structure

1.  **`IObserver` (Interface)**: Defines the `update()` method that all subscribers must implement.
2.  **`ISubject` (Interface)**: Defines methods to `attach` (subscribe), `detach` (unsubscribe), and `notify` observers.
3.  **`YouTubeChannel` (Concrete Subject)**:
    *   Maintains a list (`std::vector`) of pointers to `IObserver`.
    *   Has an `uploadVideo()` method that changes the state and triggers `notify()`.
4.  **`Subscriber` (Concrete Observer)**:
    *   Implements `update()`.
    *   Prints a message to the console when notified.
 Pattern** defines a subscription mechanism to notify multiple objects about any events that happen to the object they're observing. It promotes loose coupling: the subject doesn't care *who* the observers are, only that they implement the `IObserver` interface.
