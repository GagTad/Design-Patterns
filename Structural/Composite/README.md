
---

# FS-Sim: A File System Simulator

A C++ project designed to demonstrate the power and elegance of the **Composite Design Pattern** by modeling a simple, hierarchical file system.

## Overview

FS-Sim is a console application that represents a file system structure containing files and directories. A directory can contain multiple files as well as other sub-directories, forming a tree-like structure.

The core challenge is to perform operations on this structure, such as calculating the total size of a directory or displaying its entire contents, in a simple and uniform way. We want to treat a single file (a simple object) and a directory (a complex object) in exactly the same manner.

## The Problem: Simple vs. Complex Objects

In a file system:
-   A **File** is a simple "leaf" object. Its size is a fixed number.
-   A **Directory** is a complex "composite" object. Its size is the sum of the sizes of everything it contains (all files and all sub-directories).

Without a proper design pattern, writing a function to calculate size would involve complex logic: iterating through a directory's contents, checking the type of each item with `if/else` statements, and using recursion manually. This code would be fragile and hard to maintain.

## The Solution: The Composite Design Pattern

The **Composite** pattern is the perfect solution for this problem. It allows you to compose objects into tree structures to represent part-whole hierarchies. Most importantly, it lets clients treat individual objects (leaves) and compositions of objects (composites) **uniformly**.

### Pattern Components in FS-Sim

This project implements the key roles of the Composite pattern:

1.  **Component (`IFileSystemComponent.h`)**
    *   This is the abstract base class that provides a common interface for all objects in our tree.
    *   It declares the common operations that both files and directories must support: `getSize()` and `display()`.

2.  **Leaf (`File.h`, `File.cpp`)**
    *   Represents the "leaf" or primitive objects in the composition. A `File` has a name and a size but cannot have children.
    *   Its `getSize()` method simply returns its own size.

3.  **Composite (`Directory.h`, `Directory.cpp`)**
    *   Represents the "composite" or complex objects that can have children. A `Directory` has a name and a list of child `IFileSystemComponent` objects.
    *   Its `getSize()` method demonstrates the pattern's power: it iterates through its children and **recursively calls `getSize()` on each child**, summing the results. It doesn't need to know if a child is a `File` or another `Directory`.
    *   It also provides methods like `add()` and `remove()` to manage its children.

4.  **Client (`main.cpp`)**
    *   The `main` function acts as the client. It builds the file system tree by creating `File` and `Directory` objects.
    *   Crucially, the client interacts with all objects through the common `IFileSystemComponent` interface. It can call `getSize()` on a single file or an entire directory tree with the exact same line of code, without worrying about the object's internal complexity.

## Project Structure

```
FS-Sim/
├── main.cpp                 # Entry point: builds the file system tree and runs operations.
├── IFileSystemComponent.h   # The common Component interface.
├── File.h                   # Header for the Leaf class.
├── File.cpp                 # Implementation of the Leaf class.
├── Directory.h              # Header for the Composite class.
└── Directory.cpp            # Implementation of the Composite class.
```

## How to Build and Run

### Prerequisites
- A C++ compiler that supports the C++17 standard (e.g., g++, Clang).

### Compilation
Navigate to the project's root directory in your terminal and execute the following command:
```bash
g++ main.cpp File.cpp Directory.cpp -o FSSimApp -std=c++17
```

### Execution
Run the compiled application:
```bash
./FSSimApp
```

### Expected Output
```
==========================================
   File System Simulator (Composite)      
==========================================

--- Displaying the entire file system structure ---
[DEBUG] Calculating size for directory: root
... (Debug lines from nested getSize calls)
+ root/ (content size: 26432 bytes)
    [DEBUG] Calculating size for directory: Documents
    + Documents/ (content size: 2560 bytes)
        - report.docx (2048 bytes)
        - notes.txt (512 bytes)
    [DEBUG] Calculating size for directory: Pictures
    [DEBUG] Calculating size for directory: Vacation2023
    + Pictures/ (content size: 11776 bytes)
        - photo1.jpg (4096 bytes)
        - logo.png (1024 bytes)
        [DEBUG] Calculating size for directory: Vacation2023
        + Vacation2023/ (content size: 6656 bytes)
            - beach.jpg (3072 bytes)
            - mountain.jpg (3584 bytes)
    [DEBUG] Calculating size for directory: Music
    + Music/ (content size: 11264 bytes)
        - track1.mp3 (5120 bytes)
        - track2.mp3 (6144 bytes)
    - config.sys (256 bytes)

--- Calculating sizes of different components ---
Size of a single file (temp_report.docx): 1234 bytes
[DEBUG] Calculating size for directory: Pictures
[DEBUG] Calculating size for directory: Vacation2023
Total size of 'Pictures' directory: 11776 bytes
[DEBUG] Calculating size for directory: root
... (Debug lines from nested getSize calls)
Total size of the entire file system ('root'): 26432 bytes
```

## Key Takeaways

-   **Uniformity:** The client code is dramatically simplified because it does not need to distinguish between simple and complex objects.
-   **Recursion:** The pattern is a natural fit for recursive data structures and allows for elegant, recursive solutions to problems like calculating a total size or value.
-   **Extensibility (Open/Closed Principle):** The system is easy to extend. We could add new types of components (e.g., a `Shortcut` or `SymbolicLink` class that inherits from `IFileSystemComponent`) without ever modifying the client code or the existing `Directory` class.
