#ifndef MANAGER_H
#define MANAGER_H

#include "SupportHandler.h"

class Manager : public SupportHandler {
public:
    void handleRequest(int severity, const std::string& issue) override;
};

#endif 
