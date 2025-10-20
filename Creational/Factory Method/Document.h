#pragma once

#include <iostream>
#include <string>
 
// 1. Abstract Product (Product)
class Document {
public:
    virtual ~Document() = default;
    virtual void open() const = 0;
    virtual void save() const = 0;
    virtual void close() const = 0;
};

// 2. Concrete Product 1
class TextDocument : public Document {
public:
    void open() const override {
        std::cout << "Opening Text Document..." << std::endl;
    }
    void save() const override {
        std::cout << "Saving Text Document..." << std::endl;
    }
    void close() const override {
        std::cout << "Closing Text Document..." << std::endl;
    }
};

// 3. Concrete Product 2
class SpreadsheetDocument : public Document {
public:
    void open() const override {
        std::cout << "Opening Spreadsheet Document..." << std::endl;
    }
    void save() const override {
        std::cout << "Saving Spreadsheet Document..." << std::endl;
    }
    void close() const override {
        std::cout << "Closing Spreadsheet Document..." << std::endl;
    }
};
