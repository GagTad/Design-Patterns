#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H

#include <iostream>
#include <string>

// Subsystem 1
class TV {
public:
    void turnOn();
    void turnOff();
    void setInput(const std::string& input);
};

// Subsystem 2
class SoundSystem {
public:
    void turnOn();
    void turnOff();
    void setVolume(int level);
};

// Subsystem 3
class RoomLights {
public:
    void dim(int level);
    void turnOnFull();
};

#endif 
