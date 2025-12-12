#include <iostream>
#include "Level1Support.h"
#include "Level2Support.h"
#include "Manager.h"

int main() {
    SupportHandler* level1 = new Level1Support();
    SupportHandler* level2 = new Level2Support();
    SupportHandler* manager = new Manager();

    // Level 1 -> Level 2 -> Manager
    level1->setNext(level2);
    level2->setNext(manager);
  
    level1->handleRequest(1, "Forgot Password");

    level1->handleRequest(2, "Database not responding");

    level1->handleRequest(3, "Server Exploded");

    delete level1;
    delete level2;
    delete manager;

    return 0;
}
