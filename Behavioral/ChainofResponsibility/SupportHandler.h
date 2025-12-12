#ifndef SUPPORTHANDLER_H
#define SUPPORTHANDLER_H

#include <string>

class SupportHandler {
protected:
    SupportHandler* nextHandler;

public:
    SupportHandler();
    virtual ~SupportHandler() = default;

    void setNext(SupportHandler* handler);

    virtual void handleRequest(int severity, const std::string& issue) = 0;
};

#endif 
