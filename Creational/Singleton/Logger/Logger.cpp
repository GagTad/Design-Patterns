#include "logger.h"


Logger& Logger::getInstance() {
	static Logger instance;
	return instance;
}

void Logger::log(const std::string& message) {
	std::cout <<"[LOG]" << message << std::endl;
}

Logger::Logger() {
	std::cout << "Logger initialized." << std::endl;
}

Logger::~Logger() {
	std::cout << "Logger destroyed." << std::endl;
}