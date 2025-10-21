#pragma once

class ComputerBuilder; 

class ComputerDirector {
public:
     
    void constructGamingPC(ComputerBuilder& builder);
    void constructOfficePC(ComputerBuilder& builder);
};
