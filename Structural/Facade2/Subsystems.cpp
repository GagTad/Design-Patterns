#include "Subsystems.h"

// TV Implementation 
void TV::turnOn() { std::cout << "TV: Turned ON." << std::endl; }
void TV::turnOff() { std::cout << "TV: Turned OFF." << std::endl; }
void TV::setInput(const std::string& input) { std::cout << "TV: Input set to " << input << "." << std::endl; }

//  SoundSystem Implementation 
void SoundSystem::turnOn() { std::cout << "Sound: Turned ON." << std::endl; }
void SoundSystem::turnOff() { std::cout << "Sound: Turned OFF." << std::endl; }
void SoundSystem::setVolume(int level) { std::cout << "Sound: Volume set to " << level << "." << std::endl; }

//  RoomLights Implementation 
void RoomLights::dim(int level) { std::cout << "Lights: Dimmed to " << level << "%." << std::endl; }
void RoomLights::turnOnFull() { std::cout << "Lights: Turned ON fully." << std::endl; }
