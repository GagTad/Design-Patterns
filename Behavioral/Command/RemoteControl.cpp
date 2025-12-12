#include "RemoteControl.h"
#include <iostream>

void RemoteControl::setCommand(ICommand* command) {
    slot = command;
}

void RemoteControl::pressButton() {
    if (slot) {
        slot->execute();
    }
}

void RemoteControl::pressUndo() {
    if (slot) {
        std::cout << "[Undoing last action]  ";
        slot->undo();
    }
}
