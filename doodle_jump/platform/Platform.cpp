#include "Platform.h"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <time.h>

Platform::Platform() {
    updateCount = 0;
    type = PlatformType::NORMAL;

    int x = 0;
    int y = 800;

    sprite.setPosition((float)x, (float)y);
}

void Platform::useGenerator(const sf::Vector2f& lastPlatformCoordinates) {
    std::cout << "Platform constructor called\n";
    
    PlatformType platformType = PlatformType::NORMAL;
    updateCount = 0;
    int random = rand() % 100;

    // 10% chance of generating a breakable platform
    // 10% chance of generating a moving platform
    // 10% chance of generating a boost platform
    // 70% chance of generating a normal platform

    if (random < 10) {
        platformType = PlatformType::BREAKABLE;
    } else if (random < 20) {
        platformType = PlatformType::MOVING;
    } else if (random < 30) {
        platformType = PlatformType::BOOST;
    }

    int x = rand() % 700;
    while (abs((float)x - lastPlatformCoordinates.x) < 50.0f) {
        x = rand() % 700;
    }

    int y = (int)lastPlatformCoordinates.y - 75;

    type = platformType;

    switch (platformType) {
    case PlatformType::NORMAL:
        texture.loadFromFile("bin/assets/platform.png");
        break;
    case PlatformType::BREAKABLE:
        texture.loadFromFile("bin/assets/platform_break.png");
        break;
    case PlatformType::MOVING:
        texture.loadFromFile("bin/assets/platform_moving.png");
        break;
    case PlatformType::BOOST:
        texture.loadFromFile("bin/assets/platform_boost.png");
        break;
    default:
        break;
    }
    sprite.setTexture(texture);
    sprite.setPosition((float)x, (float)y);
}

std::ostream& operator<<(std::ostream& os, const PlatformType& platformType) {
    switch (platformType) {
    case PlatformType::NORMAL:
        os << "NORMAL";
        break;
    case PlatformType::BREAKABLE:
        os << "BREAKABLE";
        break;
    case PlatformType::MOVING:
        os << "MOVING";
        break;
    case PlatformType::BOOST:
        os << "BOOST";
        break;
    default:
        os << "UNKNOWN";
        break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Platform& platform) {
    sf::Vector2f coordinates = platform.getSprite().getPosition();
    os << "Platform: coordinates = (" << std::to_string(coordinates.x) << ", " << std::to_string(coordinates.y) << "), type = " << platform.type;
    return os;
}

void Platform::moveSprite(const sf::Vector2f& coordinates_) {
    sprite.move(coordinates_);
}

void Platform::animateMovement() {
    if (updateCount < 100) {
        sprite.move({ -1.0f, 0.0f });
    }
    else if (updateCount < 200) {
        sprite.move({ 1.0f, 0.0f });
    }
    else {
        updateCount = 0;
    }
    updateCount++;
}

PlatformType Platform::getType() const {
    return type;
}

sf::Sprite Platform::getSprite() const {
    return sprite;
}

// sf::Texture Platform::getTexture() const {
//     return texture;
// }