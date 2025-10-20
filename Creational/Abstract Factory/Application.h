#pragma once

#include "IGUIFactory.h"
#include <memory>


class Application {
private:
    std::unique_ptr<IButton> m_button;
    std::unique_ptr<ICheckbox> m_checkbox;
    const IGUIFactory& m_factory;

public:
    Application(const IGUIFactory& factory);
    void createUI();
};
