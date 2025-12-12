#include <iostream>
#include "TV.h"
#include "Radio.h"
#include "RemoteControl.h"
#include "AdvancedRemote.h"

int main() {
    std::cout << " Basic Remote with TV " << std::endl;
    IDevice* myTV = new TV();
    RemoteControl* basicRemote = new RemoteControl(myTV);
    
    basicRemote->togglePower();


    std::cout << " Advanced Remote with Radio" << std::endl;
    IDevice* myRadio = new Radio();
    AdvancedRemote* smartRemote = new AdvancedRemote(myRadio);

    smartRemote->togglePower();
    smartRemote->mute();      

    delete basicRemote;
    delete myTV;
    delete smartRemote;
    delete myRadio;

    return 0;
}
