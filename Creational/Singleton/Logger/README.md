

# C++ Singleton Pattern Implementation (Logger Example)

This repository contains a simple yet robust implementation of the **Singleton** design pattern in C++. The implementation uses a `Logger` class, which is a classic and practical use case for the Singleton pattern.

## Project Purpose

The primary goal of this project is to demonstrate the practical application of the Singleton design pattern, translating theoretical knowledge into working code. It showcases how to ensure that a class has **only one instance** and provides a single, global point of access to it.

## Key Implementation Details

This implementation follows modern C++ best practices to ensure the integrity and safety of the Singleton.

1.  **Meyers' Singleton**
    The implementation uses the "Meyers' Singleton" approach, which is a modern and thread-safe (since C++11) technique. The static instance is declared inside the `getInstance()` function, guaranteeing that it is created only upon the first call (lazy initialization).

    ```cpp
    static Logger& getInstance() {
        static Logger instance; // Instantiated only once
        return instance;
    }
    ```

2.  **Private Constructor and Destructor**
    The constructor (`Logger()`) and destructor (`~Logger()`) are declared as `private`. This prevents external code from creating instances of the class directly, either on the stack or with `new Logger()`, which is a core requirement of the Singleton pattern.

3.  **Deleted Copy Operations**
    The copy constructor and copy assignment operator are explicitly deleted using `= delete`. This prevents both accidental and intentional copying of the instance, which would violate the "one instance" rule.

    ```cpp
    Logger(const Logger&) = delete;
    const Logger& operator=(const Logger&) = delete;
    ```
   

4.  **Global Point of Access**
    The `static Logger& getInstance()` method serves as the sole entry point for accessing the singleton instance, ensuring that all parts of the application interact with the exact same object.

## File Structure

-   `logger.h`: The header file containing the declaration (interface) of the `Logger` class.
-   `logger.cpp`: The implementation file containing the definitions of the `Logger` class methods.
-   `main.cpp`: A demonstration program that shows how different functions (`testSingleton`, `dosomeWork`, `processUseData`) use the same `Logger` instance.

## How to Compile and Run

First, ensure you have a C++ compiler (like g++) installed. Open a terminal in the project's root directory and execute the following commands.

**Compile:**
```bash
g++ main.cpp logger.cpp -o singleton_logger
```

**Run:**
```bash
./singleton_logger
```


## Expected Output

When you run the program, you will see output confirming that all variables point to the same instance and that all log messages are handled by that single object.

```
Logger instance has been created.
Both logger1 and logger2 point to the same instance.
[LOG]: This is a log message from logger1.
[LOG]: This is a log message from logger2.

Address of logger1: 0x55c0a2f9d058
Address of logger2: 0x55c0a2f9d058
[LOG]: Doing some work...
[LOG]: Processing data...
Logger instance is being destroyed.
```
