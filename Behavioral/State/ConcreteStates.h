#ifndef CONCRETESTATES_H
#define CONCRETESTATES_H

#include "IState.h"

// 1. Stopped State
class StoppedState : public IState {
public:
    void pressPlay(MusicPlayer* player) override;
    void pressStop(MusicPlayer* player) override;
};

// 2. Playing State
class PlayingState : public IState {
public:
    void pressPlay(MusicPlayer* player) override;
    void pressStop(MusicPlayer* player) override;
};


#endif 
