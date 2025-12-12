#include <iostream>
#include "MusicPlayer.h"
#include "ConcreteStates.h"

int main() {
    MusicPlayer* player = new MusicPlayer(new StoppedState());

    player->pressPlay(); // Stopped -> Playing
    player->pressPlay(); // Playing -> Playing 
    player->pressStop(); // Playing -> Stopped
    player->pressStop(); // Stopped -> Stopped 

    delete player;

    return 0;
}
