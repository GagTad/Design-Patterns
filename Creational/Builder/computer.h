#pragma once

#include <iostream>
#include <string>

class ComputerBuilder;

class Computer {
private:
    std::string m_cpu;
    std::string m_ram;
    std::string m_storage;
    std::string m_gpu; 

    
    Computer() = default;
    friend class ComputerBuilder;

public:
    void show() const {
        std::cout << "Computer Configuration:" << std::endl;
        std::cout << "  CPU: " << m_cpu << std::endl;
        std::cout << "  RAM: " << m_ram << std::endl;
        std::cout << "  Storage: " << m_storage << std::endl;
        if (!m_gpu.empty()) {
            std::cout << "  GPU: " << m_gpu << std::endl;
        } else {
            std::cout << "  GPU: Integrated" << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    }
};
