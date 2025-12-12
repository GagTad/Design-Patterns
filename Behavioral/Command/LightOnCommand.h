#ifndef LIGHTONCOMMAND_H
#define LIGHTONCOMMAND_H

#include "ICommand.h"
#include "Light.h"

class LightOnCommand : public ICommand {
private:
    Light* light;

public:
    LightOnCommand(Light* l);
    void execute() override;
    void undo() override;
};

#endif 
