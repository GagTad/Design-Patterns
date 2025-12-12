#ifndef IDEVICE_H
#define IDEVICE_H

class IDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setVolume(int percent) = 0;
    virtual ~IDevice() = default;
};

#endif 
