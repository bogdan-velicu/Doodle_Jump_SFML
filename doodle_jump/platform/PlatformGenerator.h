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
    PlatformGenerator& operator=(const PlatformGenerator& platformGenerator_);
    PlatformGenerator(const PlatformGenerator& platformGenerator_);
    sf::Vector2f getLastPlatformCoordinates();
    void setLastPlatform(Platform* lastPlatform_);
};