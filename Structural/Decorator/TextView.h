#pragma once
#include <string>
#include <iostream>
#include "IVisualComponent.h"
	
class TextView : public IVisualComponent {
public:
	TextView(const std::string& component) : m_component(component) {}
	void draw() const override {
	std::cout << "Drawing TextView: " << m_component << std::endl;
	}
	void resize() override {
		std::cout << "Resizing TextView: " << m_component << std::endl;
	}

private:
	std::string m_component;

		
};
