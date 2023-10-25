#include "PlatformGenerator.h"
#include "Platform.h"

PlatformGenerator::PlatformGenerator() {
    std::cout << "PlatformGenerator constructor called\n";

    lastPlatform = new Platform();
}

PlatformGenerator::~PlatformGenerator() {
    std::cout << "PlatformGenerator destructor called\n";
}

// Platform PlatformGenerator::getLastPlatform() {
//     return lastPlatform;
// }

sf::Vector2f PlatformGenerator::getLastPlatformCoordinates() {
    return lastPlatform->getSprite().getPosition();
}

void PlatformGenerator::setLastPlatform(Platform* lastPlatform_) {
    lastPlatform = lastPlatform_;
}