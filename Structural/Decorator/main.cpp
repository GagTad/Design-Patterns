#include <iostream>
#include <memory>
#include "IVisualComponent.h"
#include "TextView.h"
#include "ConcreteDecorator.h"



int main () {

	auto textView = std::make_unique<TextView>("Hello ,Decorator ");
	auto borderedTextView = std::make_unique<BorderDecorator>(std::move(textView), 2.0);
	auto scrollableBorderedTextView = std::make_unique<ScrollDecorator>(std::move(borderedTextView), 100);

	scrollableBorderedTextView->draw();
	scrollableBorderedTextView->resize();

	return 0;

}