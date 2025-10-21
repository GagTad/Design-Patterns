#include "ComputerBuilder.h"
#include "Computer.h" 

ComputerBuilder::ComputerBuilder() {
    m_computer = std::unique_ptr<Computer>(new Computer()); // Կանչում ենք private կոնստրուկտորը
}

ComputerBuilder& ComputerBuilder::setCPU(const std::string& cpu) {
    m_computer->m_cpu = cpu;
    return *this;
}

ComputerBuilder& ComputerBuilder::setRAM(const std::string& ram) {
    m_computer->m_ram = ram;
    return *this;
}

ComputerBuilder& ComputerBuilder::setStorage(const std::string& storage) {
    m_computer->m_storage = storage;
    return *this;
}

ComputerBuilder& ComputerBuilder::setGPU(const std::string& gpu) {
    m_computer->m_gpu = gpu;
    return *this;
}

 
std::unique_ptr<Computer> ComputerBuilder::build() {
    return std::move(m_computer);
}
