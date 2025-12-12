#ifndef TV_H
#define TV_H

#include "IDevice.h"

class TV : public IDevice {
public:
    void turnOn() override;
    void turnOff() override;
    void setVolume(int percent) override;
};

#endif 
