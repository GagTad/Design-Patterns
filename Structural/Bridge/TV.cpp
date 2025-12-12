#include "TV.h"
#include <iostream>

void TV::turnOn() {
    std::cout << "TV: Turned ON." << std::endl;
}

void TV::turnOff() {
    std::cout << "TV: Turned OFF." << std::endl;
}

void TV::setVolume(int percent) {
    std::cout << "TV: Volume set to " << percent << "%." << std::endl;
}
