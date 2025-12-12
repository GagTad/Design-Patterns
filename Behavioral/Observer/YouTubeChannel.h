#ifndef YOUTUBECHANNEL_H
#define YOUTUBECHANNEL_H

#include "ISubject.h"
#include <vector>
#include <string>

class YouTubeChannel : public ISubject {
private:
    std::vector<IObserver*> observers; 
    std::string latestVideoTitle;

public:
    void attach(IObserver* observer) override;
    void detach(IObserver* observer) override;
    void notify() override;

    void uploadVideo(const std::string& title);
};

#endif
