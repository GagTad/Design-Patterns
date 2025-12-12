#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "IState.h"

class MusicPlayer {
private:
    IState* currentState;

public:
    MusicPlayer(IState* initialState);
    
    void setState(IState* state);

    void pressPlay();
    void pressStop();
};

#endif 
