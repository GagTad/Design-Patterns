#ifndef LEVEL2SUPPORT_H
#define LEVEL2SUPPORT_H

#include "SupportHandler.h"

class Level2Support : public SupportHandler {
public:
    void handleRequest(int severity, const std::string& issue) override;
};

#endif 
