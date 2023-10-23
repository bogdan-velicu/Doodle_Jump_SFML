#include "Platform.h"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <time.h>

Platform::Platform() {
    std::cout << "Platform constructor called\n";
    type = PlatformType::NORMAL;

    sprite = new sf::Sprite();
    texture.loadFromFile("assets/platform.png");
    sprite->setTexture(texture);

    int x = rand() % 700;
    int y = rand() % 300 + 300;
    sprite->setPosition((float)x, (float)y);
}

Platform::Platform(bool upperScreen) {
    std::cout << "Platform constructor called\n";
    type = PlatformType::NORMAL;

    sprite = new sf::Sprite();
    texture.loadFromFile("assets/platform.png");
    sprite->setTexture(texture);

    int x = rand() % 700;
    int y = 0;
    if (upperScreen) {
        y = rand() % 50 + 50;
    } else {
        y = rand() % 50 + 300;
    }
    sprite->setPosition((float)x, (float)y);
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

Platform::Platform(PlatformType type_) {
    std::cout << "Platform constructor called\n";
    type = type_;

    sprite = new sf::Sprite();
    texture.loadFromFile("assets/platform.png");
    sprite->setTexture(texture);

    int x = rand() % 700;
    int y = rand() % 600;
    sprite->setPosition((float)x, (float)y);
}

std::ostream& operator<<(std::ostream& os, const Platform& platform) {
    sf::Vector2f coordinates = platform.getSprite().getPosition();
    os << "Platform: coordinates = (" << std::to_string(coordinates.x) << ", " << std::to_string(coordinates.y) << "), type = " << platform.type;
    return os;
}

Platform& Platform::operator=(const Platform& platform_) = default;

Platform::~Platform() {
    std::cout << "Platform destructor called\n";
    delete sprite;
}

void Platform::moveSprite(const sf::Vector2f& coordinates_) {
    sprite->move(coordinates_);
}

PlatformType Platform::getType() const {
    return type;
}

sf::Sprite Platform::getSprite() const {
    return *sprite;
}

sf::Texture Platform::getTexture() const {
    return texture;
}