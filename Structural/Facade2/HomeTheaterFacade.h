#ifndef HOMETHEATERFACADE_H
#define HOMETHEATERFACADE_H

#include "Subsystems.h"
#include <string>

class HomeTheaterFacade {
private:
    TV* tv;
    SoundSystem* sound;
    RoomLights* lights;

public:
    HomeTheaterFacade(TV* tv, SoundSystem* sound, RoomLights* lights);

    void watchMovie(const std::string& movieName);
    void endMovie();
};

#endif
