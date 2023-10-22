#include "Platform.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>

Platform::Platform() {
    std::cout << "Platform constructor called\n";
    type = PlatformType::NORMAL;

    sf::Texture texture;
    texture.loadFromFile("assets/platform.png");
    sprite.setTexture(texture);

    int x = rand() % 700;
    int y = rand() % 500;
    sprite.setPosition((float)x, (float)y);
}

Platform::Platform(PlatformType type_) {
    std::cout << "Platform constructor called\n";
    type = type_;
}

std::ostream& operator<<(std::ostream& os, const Platform& platform) {
    sf::Vector2f coordinates = platform.getSprite().getPosition();
    os << "Platform: coordinates = (" << std::to_string(coordinates.x) << ", " << std::to_string(coordinates.y) << "), type = " << platform.type;
    return os;
}

Platform& Platform::operator=(const Platform& platform_) = default;

Platform::~Platform() {
    std::cout << "Platform destructor called\n";
}

PlatformType Platform::getType() const {
    return type;
}

sf::Sprite Platform::getSprite() const {
    return sprite;
}