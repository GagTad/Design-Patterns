#include "Computer.h"
#include "ComputerBuilder.h"
#include "ComputerDirector.h"
#include <memory>

int main() {
    std::cout << "--- Using Director to build a Gaming PC ---" << std::endl;
    ComputerBuilder gamingBuilder;
    ComputerDirector director;

    director.constructGamingPC(gamingBuilder);
    std::unique_ptr<Computer> gamingPC = gamingBuilder.build();
    gamingPC->show();

    std::cout << "--- Using Director to build an Office PC ---" << std::endl;
    ComputerBuilder officeBuilder;
    director.constructOfficePC(officeBuilder);
    std::unique_ptr<Computer> officePC = officeBuilder.build();
    officePC->show();


    std::cout << "--- Using Builder directly for a custom PC ---" << std::endl;
    ComputerBuilder customBuilder;
    std::unique_ptr<Computer> customPC = customBuilder
                                            .setCPU("AMD Ryzen 5")
                                            .setRAM("16GB DDR4")
                                            .setStorage("1TB NVMe SSD")
                                            .build();
    customPC->show();

    return 0;
}
