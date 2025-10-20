#pragma once
#include "IGUIFactory.h"
#include "MacWidget.h"

// Concrete Factory 2
class MacFactory : public IGUIFactory {
public:
    std::unique_ptr<IButton> createButton() const override {
        return std::make_unique<MacButton>();
    }
    std::unique_ptr<ICheckbox> createCheckbox() const override {
        return std::make_unique<MacCheckbox>();
    }
};
