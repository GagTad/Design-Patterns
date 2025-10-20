#include "Application.h"
#include "WinFactory.h"
#include "MacFactory.h"
#include <string>

void ClientCode(const IGUIFactory& factory) {
    Application app(factory);
    app.createUI();
}

int main() {

    std::string os_type = "Windows"; 
    
    std::cout << "Client: Application is configured to run on " << os_type << std::endl;

    if (os_type == "Windows") {
        WinFactory win_factory;
        ClientCode(win_factory);
    } else if (os_type == "macOS") {
        MacFactory mac_factory;
        ClientCode(mac_factory);
    } else {
        std::cerr << "Error: Unknown operating system." << std::endl;
        return 1;
    }

    os_type = "macOS";
    std::cout << "\nClient: Re-configuring application to run on " << os_type << std::endl;

    if (os_type == "macOS") {
        MacFactory mac_factory;
        ClientCode(mac_factory);
    }


    return 0;
}
