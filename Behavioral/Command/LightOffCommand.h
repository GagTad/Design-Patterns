#ifndef LIGHTOFFCOMMAND_H
#define LIGHTOFFCOMMAND_H

#include "ICommand.h"
#include "Light.h"

class LightOffCommand : public ICommand {
private:
    Light* light;

public:
    LightOffCommand(Light* l);
    void execute() override;
    void undo() override;
};

#endif 
