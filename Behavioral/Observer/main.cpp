#include <iostream>
#include "YouTubeChannel.h"
#include "Subscriber.h"

int main() {

    YouTubeChannel* myChannel = new YouTubeChannel();

    Subscriber* user1 = new Subscriber("Aram");
    Subscriber* user2 = new Subscriber("Ani");
    Subscriber* user3 = new Subscriber("Karen");

    myChannel->attach(user1);
    myChannel->attach(user2);
    myChannel->attach(user3);

    myChannel->uploadVideo("C++ Design Patterns Tutorial");

    std::cout << "\n(Ani unsubscribed)" << std::endl;
    myChannel->detach(user2);

    myChannel->uploadVideo("Observer Pattern Explained");

    delete myChannel;
    delete user1;
    delete user2;
    delete user3;

    return 0;
}
