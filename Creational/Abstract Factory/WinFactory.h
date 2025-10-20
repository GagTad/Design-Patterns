#pragma once
#include "IGUIFactory.h"
#include "WindowsWidget.h"

// Concrete Factory 1
class WinFactory : public IGUIFactory {
public:
    std::unique_ptr<IButton> createButton() const override {
        return std::make_unique<WinButton>();
    }
    std::unique_ptr<ICheckbox> createCheckbox() const override {
        return std::make_unique<WinCheckbox>();
    }
};
