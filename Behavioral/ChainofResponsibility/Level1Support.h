#ifndef LEVEL1SUPPORT_H
#define LEVEL1SUPPORT_H

#include "SupportHandler.h"

class Level1Support : public SupportHandler {
public:
    void handleRequest(int severity, const std::string& issue) override;
};

#endif 
