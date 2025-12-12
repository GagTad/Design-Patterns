#include "Subscriber.h"
#include <iostream>

Subscriber::Subscriber(const std::string& n) : name(n) {}

void Subscriber::update(const std::string& videoTitle) {
    std::cout << "Hey " << name << ", new video uploaded: " << videoTitle << std::endl;
}
