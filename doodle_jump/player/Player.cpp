#include "Player.h"
#include <iostream>

Player::Player() {
    std::cout << "Player constructor called\n";

    xVelocity = 0;
    yVelocity = 0;

    texture = sf::Texture();
    texture.loadFromFile("assets/player.png");

    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setPosition(100, 100);
}

Player::~Player() {
    std::cout << "Player destructor called\n";
}

sf::Sprite Player::getSprite() const {
    return sprite;
}

sf::Texture Player::getTexture() const {
    return texture;
}

void Player::jump() {
    yVelocity = -5.0f;
}

void Player::moveLeft() {
    if (xVelocity > -2.0f)
        xVelocity -= 0.5f;
}

void Player::moveRight() {
    if (xVelocity < 2.0f)
        xVelocity += 0.5f;
}

void Player::handleMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        moveRight();
    }

    // Handle horizontal movement
    if (xVelocity > 0.0f) {
        xVelocity -= 0.1f;
    }
    else if (xVelocity < 0.0f) {
        xVelocity += 0.1f;
    }
    else if (xVelocity == 0.1f || xVelocity == -0.1f) {
        xVelocity = 0.0f;
    }

    // Handle gravity
    if (yVelocity < 5.0f) // Max falling speed
        yVelocity += 0.2f;

    // Handle ground collision
    if (sprite.getPosition().y > 500.0f)
        jump();
}

void Player::update() {
    handleMovement();

    sf::Vector2f coordinates = sprite.getPosition();
    coordinates.x += xVelocity;
    coordinates.y += yVelocity;
    sprite.setPosition(coordinates);
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    sf::Vector2f coordinates = player.getSprite().getPosition();
    out << "Player: coordinates = (" << coordinates.x << ", " << coordinates.y << ")" <<
        ", xVelocity = " << player.xVelocity << ", yVelocity = " << player.yVelocity;
    return out;
}

sf::Vector2f Player::getCoordinates() const {
    return sprite.getPosition();
}

void Player::setCoordinates(const sf::Vector2f& coordinates_) {
    sprite.setPosition(coordinates_);
}