#ifndef ISTATE_H
#define ISTATE_H

class MusicPlayer;

class IState {
public:
    virtual void pressPlay(MusicPlayer* player) = 0;
    virtual void pressStop(MusicPlayer* player) = 0;
    virtual ~IState() = default;
};

#endif 
