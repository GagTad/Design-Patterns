#pragma once
#include <memory>
#include <iostream>
#include "ComponentDecorator.h"
#include "IVisualComponent.h"


//concrete decorator A 

class BorderDecorator : public ComponentDecorator {
public:
	BorderDecorator(std::unique_ptr<IVisualComponent> component, double borderWidth)
		: ComponentDecorator(std::move(component)), borderWidth(borderWidth) {}
	void draw() const override {
		ComponentDecorator::draw();
		drawBorder();
		
	}
	void drawBorder() const {
		std::cout << "ComponentDecorator adding border." << std::endl;
		std::cout << "Drawing border with width: " << borderWidth << std::endl;
	}
private:
	double borderWidth;
};

//concrete Decorator B
class ScrollDecorator : public ComponentDecorator {

public:
	ScrollDecorator(std::unique_ptr<IVisualComponent> component, int initialPosition)
		: ComponentDecorator(std::move(component)), scrollPosition(initialPosition) {
	}
	void draw() const override {
		ComponentDecorator::draw();
		drawScrollTo();
	}
	void drawScrollTo() const {
		std::cout << "ComponentDecorator adding scrolling functionality." << std::endl;
		std::cout << "Scrolling to position: " << scrollPosition << std::endl;
	}

private:
	int scrollPosition;
};