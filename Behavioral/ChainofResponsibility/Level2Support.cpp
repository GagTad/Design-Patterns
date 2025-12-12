#include "Level2Support.h"
#include <iostream>

void Level2Support::handleRequest(int severity, const std::string& issue) {
    if (severity == 2) {
        std::cout << "[Level 2] Advanced issue resolved: " << issue << std::endl;
    } else if (nextHandler != nullptr) {
        std::cout << "[Level 2] Cannot handle. Passing to Manager" << std::endl;
        nextHandler->handleRequest(severity, issue);
    } else {
        std::cout << "Issue is too complex, and no one is left to solve it!" << std::endl;
    }
}
