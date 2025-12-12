#ifndef RADIO_H
#define RADIO_H

#include "IDevice.h"

class Radio : public IDevice {
public:
    void turnOn() override;
    void turnOff() override;
    void setVolume(int percent) override;
};

#endif 
