#pragma once
#include <memory>
#include "IVisualComponent.h"



class ComponentDecorator : public IVisualComponent {	
public:
	ComponentDecorator(std::unique_ptr<IVisualComponent> component) 
		: md_component(std::move(component)) {}

	void draw() const  override {
		if (md_component) {
			md_component->draw();
		}
	}
	void resize() override {
		if (md_component) {
			md_component->resize();
		}
	}

protected:
	std::unique_ptr<IVisualComponent> md_component;
};

