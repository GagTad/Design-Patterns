#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include "IDevice.h"

class RemoteControl {
protected:
    IDevice* device;

public:
    RemoteControl(IDevice* dev);
    virtual void togglePower(); 
    virtual ~RemoteControl() = default;
};

#endif 
