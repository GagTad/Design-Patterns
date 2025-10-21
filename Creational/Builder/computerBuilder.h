#pragma once

#include <string>
#include <memory> 
 
class Computer;

class ComputerBuilder {
private:
    std::unique_ptr<Computer> m_computer;

public:
    ComputerBuilder();
 
    ComputerBuilder& setCPU(const std::string& cpu);
    ComputerBuilder& setRAM(const std::string& ram);
    ComputerBuilder& setStorage(const std::string& storage);
    ComputerBuilder& setGPU(const std::string& gpu);
 
    std::unique_ptr<Computer> build();
};
