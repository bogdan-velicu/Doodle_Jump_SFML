#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "./Platform.h"

class PlatformGenerator {
private:
    Platform* lastPlatform;
public:
    PlatformGenerator();
    ~PlatformGenerator();
    // Platform getLastPlatform();
    sf::Vector2f getLastPlatformCoordinates();
    void setLastPlatform(Platform* lastPlatform_);
};