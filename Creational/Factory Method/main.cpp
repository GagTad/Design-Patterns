#include "Application.h"
#include <iostream>
#include <memory>


void ClientCode(Application& app) {
    app.newDocument();
}

int main() {
    std::cout << "--- Testing with TextApplication ---" << std::endl;
    TextApplication textApp;
    ClientCode(textApp);

    std::cout << "\n-------------------------------------\n" << std::endl;

    std::cout << "--- Testing with SpreadsheetApplication ---" << std::endl;
    SpreadsheetApplication spreadsheetApp;
    ClientCode(spreadsheetApp);

    return 0;
}
