#pragma once
#include "IWidget.h"

// Concrete Product A2
class MacButton : public IButton {
public:
    void paint() const override {
        std::cout << "Painting a macOS button." << std::endl;
    }
};

// Concrete Product B2
class MacCheckbox : public ICheckbox {
public:
    void paint() const override {
        std::cout << "Painting a macOS checkbox." << std::endl;
    }
};
