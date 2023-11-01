#include "Powerups.h"

#include <iostream>
#include <ostream>

Powerups::Powerups() {
    std::cout << "Powerups constructor called\n";
    updateCount = 0;
    type = PowerupsType::JETPACK;
    gameObject = nullptr;
}

Powerups::~Powerups() {
    std::cout << "Powerups destructor called\n";
}

std::ostream& operator<<(std::ostream& out, const PowerupsType& powerupsType) {
    switch (powerupsType) {
        case PowerupsType::ROCKET:
            out << "Rocket";
            break;
        case PowerupsType::SHIELD:
            out << "Shield";
            break;
        case PowerupsType::JETPACK:
            out << "Jetpack";
            break;
    }
    return out;
}

void Powerups::setGameObject(GameObject *gameObject_) {
    gameObject = gameObject_;
}

void Powerups::useGenerator(const sf::Vector2f& lastPlatformCoordinates) {
    std::cout << "Powerups constructor called\n";
    
    PowerupsType powerupsType = PowerupsType::JETPACK;
    updateCount = 0;
    int random = rand() % 300;

    // 30% chance of generating a rocket powerup
    // 30% chance of generating a shield powerup
    // 30% chance of generating a jetpack powerup

    if (random < 100) {
        powerupsType = PowerupsType::ROCKET;
    } else if (random < 200) {
        powerupsType = PowerupsType::SHIELD;
    } else if (random < 300) {
        powerupsType = PowerupsType::JETPACK;
    }

    float x = lastPlatformCoordinates.x;

    float y = lastPlatformCoordinates.y - 30;

    sprite.setPosition(x, y);
    type = powerupsType;
}

std::ostream& operator<<(std::ostream& os, const Powerups& powerups) {
    os << "Powerups object\n"
        << "Type: " << powerups.type << '\n'
        << "Update count: " << powerups.updateCount << '\n';
    return os;
}

PowerupsType Powerups::getType() const {
    return type;
}

sf::Sprite Powerups::getSprite() const {
    return sprite;
}

void Powerups::moveSprite(const sf::Vector2f& coordinates_) {
    sprite.move(coordinates_);
}

void Powerups::animateMovement() {
    updateCount++;
    if (updateCount == 100) {
        updateCount = 0;
    }
    sprite.move(0.0f, 1.0f);
}

void Powerups::draw(sf::RenderWindow& window, const sf::Sprite& sprite_) {
    // window.draw(sprite_);
    if (gameObject != nullptr) {
        gameObject->draw(window, sprite_);
    }
    else {
        std::cout << "Powerups::draw() gameObject is nullptr\n";
    }
}