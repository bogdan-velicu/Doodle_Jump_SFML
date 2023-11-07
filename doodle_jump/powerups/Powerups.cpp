#include "Powerups.h"

#include <iostream>
#include <ostream>

Powerups::Powerups() {
    std::cout << "Powerups constructor called\n";
    updateCount = 0;
    type = PowerupsType::JETPACK;
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

Powerups& Powerups::operator=(const Powerups& powerups) {
    std::cout << "Powerups copy assignment operator called\n";
    if (this != &powerups) {
        GameObject::operator=(powerups);
        type = powerups.type;
        updateCount = powerups.updateCount;
    }
    return *this;
}

Powerups::Powerups(const Powerups& powerups) : GameObject(powerups) {
    std::cout << "Powerups copy constructor called\n";
    type = powerups.type;
    updateCount = powerups.updateCount;
}

void Powerups::useGenerator(const sf::Vector2f& lastPlatformCoordinates) {
    std::cout << "Powerups constructor called\n";
    
    PowerupsType powerupsType = PowerupsType::JETPACK;
    updateCount = 0;
    // int random = rand() % 300;

    // if (random < 100) {
    //     powerupsType = PowerupsType::ROCKET;
    // } else if (random < 200) {
    //     powerupsType = PowerupsType::SHIELD;
    // } else {
    //     powerupsType = PowerupsType::JETPACK;
    // }

    float x = lastPlatformCoordinates.x + 20;

    float y = lastPlatformCoordinates.y - 100;

    setSpritePos({x, y});
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

// void Powerups::animateMovement() {
//     updateCount++;
//     if (updateCount == 100) {
//         updateCount = 0;
//     }
//     sprite.move(0.0f, 1.0f);
// }