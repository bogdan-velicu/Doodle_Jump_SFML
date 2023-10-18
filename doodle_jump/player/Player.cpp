#include "Player.h"
#include <iostream>

Player::Player() {
    std::cout << "Player constructor called\n";
    coordinates = Coordinates(0, 0);
}

Player::Player(const Coordinates& coordinates_) {
    std::cout << "Player constructor called\n";
    coordinates = coordinates_;
}

Player::~Player() {
    std::cout << "Player destructor called\n";
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Player: " << player.coordinates;
    return out;
}

Coordinates Player::getCoordinates() const {
    return coordinates;
}