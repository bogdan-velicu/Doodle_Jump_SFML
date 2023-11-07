#include "Player.h"
#include <iostream>

Player::Player() : GameObject() {
    std::cout << "Player constructor called\n";
    currentHeight = 0;
    health = 3;

    xVelocity = 0;
    yVelocity = 0;

    loadTexture("assets/Doodle-Ninja.png");
    setSpritePos({400, 550});

    setSpriteOrigin({getSprite().getLocalBounds().width / 2, getSprite().getLocalBounds().height / 2});
    setSpriteScale({-1.0f, 1.0f});
}

void Player::setYVelocity(float yVelocity_) {
    yVelocity = yVelocity_;
}

float Player::getYVelocity() const {
    return yVelocity;
}

sf::Vector2f Player::getVelocity() const {
    return {xVelocity, yVelocity};
}

void Player::setHealth(int health_) {
    health = health_;
}

void Player::jump() {
    yVelocity = -12.0f;
    // state = PlayerState::JUMPING;
}

void Player::moveLeft() {
    if (xVelocity > -5.0f) {
        xVelocity -= 1.0f;
        if (state == PlayerState::MOVING_RIGHT)
            setSpriteScale({-1.0f, 1.0f});
        state = PlayerState::MOVING_LEFT;
    }
}

void Player::moveRight() {
    if (xVelocity < 5.0f) {
        xVelocity += 1.0f;
        if (state == PlayerState::MOVING_LEFT)
            setSpriteScale({-1.0f, 1.0f});
        state = PlayerState::MOVING_RIGHT;
    }
}

void Player::handleMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        moveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        moveRight();
    }
    else {
        // Handle horizontal movement
        if (xVelocity > 0.0f) {
            xVelocity -= 0.5f;
        }
        else if (xVelocity < 0.0f) {
            xVelocity += 0.5f;
        }
        else if (xVelocity == 0.3f || xVelocity == -0.3f) {
            xVelocity = 0.0f;
        }
    }

    // Handle moving off screen
    if (getSprite().getPosition().x < 0.0f) {
        setSpritePosition({800.0f, getSprite().getPosition().y});
    }
    else if (getSprite().getPosition().x > 800.0f) {
        setSpritePosition({0.0f, getSprite().getPosition().y});
    }

    // Handle gravity
    if (yVelocity < 4.0f) // Max falling speed
        yVelocity += 0.4f;
}

void Player::update() {
    handleMovement();
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    sf::Vector2f coordinates = player.getSprite().getPosition();
    out << "Player: coordinates = (" << coordinates.x << ", " << coordinates.y << ")" <<
        ", xVelocity = " << player.xVelocity << ", yVelocity = " << player.yVelocity;
    return out;
}