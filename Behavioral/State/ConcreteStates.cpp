#include "ConcreteStates.h"
#include "MusicPlayer.h"
#include <iostream>

// StoppedState Impl
void StoppedState::pressPlay(MusicPlayer* player) {
    std::cout << "[Stopped] -> Play pressed. Starting music..." << std::endl;
    player->setState(new PlayingState()); 
    delete this; 
}

void StoppedState::pressStop(MusicPlayer* player) {
    std::cout << "[Stopped] -> Stop pressed. Already stopped." << std::endl;
}


// PlayingState Impl 
void PlayingState::pressPlay(MusicPlayer* player) {
    std::cout << "[Playing] -> Play pressed. Already playing." << std::endl;
}

void PlayingState::pressStop(MusicPlayer* player) {
    std::cout << "[Playing] -> Stop pressed. Stopping music..." << std::endl;
    player->setState(new StoppedState());
    delete this;
}
