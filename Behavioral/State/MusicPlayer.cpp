#include "MusicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer(IState* initialState) : currentState(initialState) {}

void MusicPlayer::setState(IState* state) {
    currentState = state;
}

void MusicPlayer::pressPlay() {
    currentState->pressPlay(this);
}

void MusicPlayer::pressStop() {
    currentState->pressStop(this);
}
