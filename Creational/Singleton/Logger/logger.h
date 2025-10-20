#pragma once

#include <iostream>
#include <string>

class Logger {
public:
	static Logger& getInstance();
	void log(const std::string& message);

	Logger(const Logger&) = delete;
	const Logger& operator=(const Logger&) = delete;

private:
	Logger() ;
	~Logger();

};
