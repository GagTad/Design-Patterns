#include "ComputerDirector.h"
#include "ComputerBuilder.h"

void ComputerDirector::constructGamingPC(ComputerBuilder& builder) {
    builder.setCPU("Intel Core i9")
           .setRAM("32GB DDR5")
           .setStorage("2TB NVMe SSD")
           .setGPU("NVIDIA RTX 4090");
}

void ComputerDirector::constructOfficePC(ComputerBuilder& builder) {
    builder.setCPU("Intel Core i5")
           .setRAM("16GB DDR4")
           .setStorage("512GB SATA SSD"); 
}
