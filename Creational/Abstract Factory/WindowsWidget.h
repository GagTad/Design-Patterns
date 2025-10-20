#pragma once
#include "IWidget.h"

// Concrete Product A1
class WinButton : public IButton {
public:
    void paint() const override {
        std::cout << "Painting a Windows button." << std::endl;
    }
};

// Concrete Product B1
class WinCheckbox : public ICheckbox {
public:
    void paint() const override {
        std::cout << "Painting a Windows checkbox." << std::endl;
    }
};
