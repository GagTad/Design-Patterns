#ifndef ADVANCEDREMOTE_H
#define ADVANCEDREMOTE_H

#include "RemoteControl.h"

class AdvancedRemote : public RemoteControl {
public:
    AdvancedRemote(IDevice* dev);
    void mute(); 
};

#endif 
