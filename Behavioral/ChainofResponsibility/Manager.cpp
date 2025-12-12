#include "Manager.h"
#include <iostream>

void Manager::handleRequest(int severity, const std::string& issue) {
    if (severity >= 3) {
        std::cout << "[Manager] Critical issue handled: " << issue << std::endl;
    } else {
         std::cout << "[Manager] Even I cannot solve this!" << std::endl;
    }
}
