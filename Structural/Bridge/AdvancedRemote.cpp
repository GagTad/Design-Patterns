#include "AdvancedRemote.h"
#include <iostream>

AdvancedRemote::AdvancedRemote(IDevice* dev) : RemoteControl(dev) {}

void AdvancedRemote::mute() {
    std::cout << "Advanced Remote: Muting device..." << std::endl;
    device->setVolume(0);
}
