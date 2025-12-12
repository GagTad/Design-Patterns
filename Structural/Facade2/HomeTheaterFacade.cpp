#include "HomeTheaterFacade.h"
#include <iostream>

HomeTheaterFacade::HomeTheaterFacade(TV* t, SoundSystem* s, RoomLights* l)
    : tv(t), sound(s), lights(l) {}

void HomeTheaterFacade::watchMovie(const std::string& movieName) {
    lights->dim(10);
    tv->turnOn();           
    tv->setInput("Netflix"); 
    sound->turnOn();         
    sound->setVolume(50);    
    std::cout << "Movie started: " << movieName << std::endl;
}

void HomeTheaterFacade::endMovie() {
    lights->turnOnFull();
    tv->turnOff();
    sound->turnOff();
}
