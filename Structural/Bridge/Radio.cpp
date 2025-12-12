#include "Radio.h"
#include <iostream>

void Radio::turnOn() {
    std::cout << "Radio: Playing music." << std::endl;
}

void Radio::turnOff() {
    std::cout << "Radio: Silence." << std::endl;
}

void Radio::setVolume(int percent) {
    std::cout << "Radio: Volume is now " << percent << "%." << std::endl;
}
