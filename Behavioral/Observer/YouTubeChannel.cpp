#include "YouTubeChannel.h"
#include <algorithm> 
#include <iostream>

void YouTubeChannel::attach(IObserver* observer) {
    observers.push_back(observer);
}

void YouTubeChannel::detach(IObserver* observer) {
    auto it = std::remove(observers.begin(), observers.end(), observer);
    observers.erase(it, observers.end());
}

void YouTubeChannel::notify() {
    for (IObserver* observer : observers) {
        observer->update(latestVideoTitle);
    }
}

void YouTubeChannel::uploadVideo(const std::string& title) {
    this->latestVideoTitle = title;
    std::cout << "\n[Channel] Uploading new video: " << title << "..." << std::endl;
    notify();
