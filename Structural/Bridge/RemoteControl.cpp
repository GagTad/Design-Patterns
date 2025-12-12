#include "RemoteControl.h"
#include <iostream>

RemoteControl::RemoteControl(IDevice* dev) : device(dev) {}

void RemoteControl::togglePower() {
    std::cout << "Remote: Toggling power button..." << std::endl;
    device->turnOn(); 
}
