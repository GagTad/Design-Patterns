#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "IObserver.h"
#include <string>

class Subscriber : public IObserver {
private:
    std::string name;

public:
    Subscriber(const std::string& name);
    void update(const std::string& videoTitle) override;
};

#endif 
