#pragma once
#include <iostream>
#include <string>

// Abstract Product A
class IButton {
public:
    virtual ~IButton() = default;
    virtual void paint() const = 0;
};

// Abstract Product B
class ICheckbox {
public:
    virtual ~ICheckbox() = default;
    virtual void paint() const = 0;
};
