#include <iostream>
#include "Light.h"
#include "LightOnCommand.h"
#include "LightOffCommand.h"
#include "RemoteControl.h"

int main() {

    Light* livingRoomLight = new Light();

    ICommand* lightsOn = new LightOnCommand(livingRoomLight);
    ICommand* lightsOff = new LightOffCommand(livingRoomLight);

    RemoteControl* remote = new RemoteControl();

    std::cout << "Pressing ON " << std::endl;
    remote->setCommand(lightsOn);
    remote->pressButton();

    remote->pressUndo();

    std::cout << "Pressing OFF " << std::endl;
    remote->setCommand(lightsOff);
    remote->pressButton();

    remote->pressUndo();

    delete livingRoomLight;
    delete lightsOn;
    delete lightsOff;
    delete remote;

    return 0;
}
