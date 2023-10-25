#include "PlatformGenerator.h"

// sf::Vector2f PlatformGenerator::lastPlatformCoordinates = { 350.0f, 600.0f };
Platform* PlatformGenerator::lastPlatform = nullptr;
PlatformType PlatformGenerator::lastPlatformType = PlatformType::NORMAL;

// sf::Vector2f PlatformGenerator::getLastPlatformCoordinates() {
//     return lastPlatformCoordinates;
// }

Platform* PlatformGenerator::getLastPlatform() {
    return lastPlatform;
}

// PlatformType PlatformGenerator::getLastPlatformType() {
//     return lastPlatformType;
// }

// void PlatformGenerator::setLastPlatformCoordinates(const sf::Vector2f& lastPlatformCoordinates_) {
//     lastPlatformCoordinates = lastPlatformCoordinates_;
// }

void PlatformGenerator::setLastPlatform(Platform* lastPlatform_) {
    lastPlatform = lastPlatform_;
}

void PlatformGenerator::setLastPlatformType(PlatformType lastPlatformType_) {
    lastPlatformType = lastPlatformType_;
}