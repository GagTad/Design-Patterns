#include <iostream>
#include "logger.h"

void testSingleton() {
	Logger& logger1 = Logger::getInstance();
	Logger& logger2 = Logger::getInstance();
	if (&logger1 == &logger2) {
		std::cout << "Both logger1 and logger2 point to the same instance." << std::endl;
	}
	else {
		std::cout << "logger1 and logger2 are different instances." << std::endl;
	}
	logger1.log("This is a log message from logger1.");
	logger2.log("This is a log message from logger2.");
	std::cout << "\nAddress of logger1: " << &logger1 << std::endl;
	std::cout << "Address of logger2: " << &logger2 << std::endl;
}

void dosomeWork() {
	Logger::getInstance().log("Doing some work...");
}

void processUseData() {
	Logger::getInstance().log("Processing data...");
}


int main() {

	testSingleton();
	dosomeWork();
	processUseData();
	return 0;
}