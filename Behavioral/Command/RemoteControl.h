#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include "ICommand.h"

class RemoteControl {
private:
    ICommand* slot;

public:
    void setCommand(ICommand* command);
    void pressButton();
    void pressUndo();
};

#endif 
