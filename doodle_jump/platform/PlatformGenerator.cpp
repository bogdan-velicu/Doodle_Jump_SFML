#include "PlatformGenerator.h"
#include "Platform.h"

PlatformGenerator::PlatformGenerator() {
    std::cout << "PlatformGenerator constructor called\n";

    lastPlatform = new Platform();
}

PlatformGenerator::~PlatformGenerator() {
    std::cout << "PlatformGenerator destructor called\n";
}

PlatformGenerator& PlatformGenerator::operator=(const PlatformGenerator& platformGenerator_) {
    std::cout << "PlatformGenerator copy assignment called\n";
    if (this != &platformGenerator_) {
        lastPlatform = platformGenerator_.lastPlatform;
    }
    return *this;
}

PlatformGenerator::PlatformGenerator(const PlatformGenerator& platformGenerator_) {
    std::cout << "PlatformGenerator copy constructor called\n";
    lastPlatform = new Platform();
    *lastPlatform = *platformGenerator_.lastPlatform;
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