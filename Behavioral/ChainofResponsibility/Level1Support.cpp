#include "Level1Support.h"
#include <iostream>

void Level1Support::handleRequest(int severity, const std::string& issue) {
    if (severity == 1) {
        std::cout << "[Level 1] Simple issue fixed: " << issue << std::endl;
    } else if (nextHandler != nullptr) {
        std::cout << "[Level 1] Cannot handle. Passing to Level 2" << std::endl;
        nextHandler->handleRequest(severity, issue);
    } else {
        std::cout << "Issue is too complex, and no one is left to solve it!" << std::endl;
    }
}
