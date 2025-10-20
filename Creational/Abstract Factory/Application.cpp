#include "Application.h"
#include <iostream>

Application::Application(const IGUIFactory& factory) : m_factory(factory) {}

void Application::createUI() {
    std::cout << "Application: Creating UI elements using the provided factory." << std::endl;
    m_button = m_factory.createButton();
    m_checkbox = m_factory.createCheckbox();
    

    m_button->paint();
    m_checkbox->paint();
}
