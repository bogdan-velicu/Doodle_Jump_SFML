#pragma once

#include <SFML/Graphics.hpp>
#include "./Platform.h"

class PlatformGenerator {
private:
    // static sf::Vector2f lastPlatformCoordinates;
    static PlatformType lastPlatformType;
    static Platform* lastPlatform;
public:
    // static sf::Vector2f getLastPlatformCoordinates();
    static Platform* getLastPlatform();
    // static PlatformType getLastPlatformType();

    // static void setLastPlatformCoordinates(const sf::Vector2f& lastPlatformCoordinates_);
    static void setLastPlatform(Platform* lastPlatform_);
    static void setLastPlatformType(PlatformType lastPlatformType_);
};