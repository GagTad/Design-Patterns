#include <iostream>
#include "Subsystems.h"
#include "HomeTheaterFacade.h"

int main() {
    TV* myTV = new TV();
    SoundSystem* mySound = new SoundSystem();
    RoomLights* myLights = new RoomLights();

    HomeTheaterFacade* homeTheater = new HomeTheaterFacade(myTV, mySound, myLights);

    homeTheater->watchMovie("Inception");

    homeTheater->endMovie();

    delete homeTheater;
    delete myTV;
    delete mySound;
    delete myLights;

    return 0;
}
