#include "Player.h"
#include <iostream>

Player::Player() {
    std::cout << "Player constructor called\n";
    currentHeight = 0;

    xVelocity = 0;
    yVelocity = 0;

    texture.loadFromFile("bin/assets/player.png");

    sprite = new sf::Sprite();
    sprite->setTexture(texture);
    sprite->setPosition(400, 550);
}

Player::~Player() {
    std::cout << "Player destructor called\n";
}

Player::Player(const Player& player_) {
    std::cout << "Player copy constructor called\n";
    currentHeight = player_.currentHeight;

    xVelocity = player_.xVelocity;
    yVelocity = player_.yVelocity;

    texture = player_.texture;

    sprite = new sf::Sprite();
    sprite->setTexture(texture);
    sprite->setPosition(player_.sprite->getPosition());
}

Player& Player::operator=(const Player& player_) {
    std::cout << "Player assignment operator called\n";
    if (this != &player_) {
        currentHeight = player_.currentHeight;

        xVelocity = player_.xVelocity;
        yVelocity = player_.yVelocity;

        texture = player_.texture;

        sprite = new sf::Sprite();
        sprite->setTexture(texture);
        sprite->setPosition(player_.sprite->getPosition());
    }
    return *this;
}

sf::Sprite Player::getSprite() const {
    return *sprite;
}

// sf::Texture Player::getTexture() const {
//     return texture;
// }

void Player::moveSprite(const sf::Vector2f& coordinates_) {
    sprite->move(coordinates_);
}

// void Player::setXVelocity(float xVelocity_) {
//     xVelocity = xVelocity_;
// }

void Player::setYVelocity(float yVelocity_) {
    yVelocity = yVelocity_;
}

float Player::getXVelocity() const {
    return xVelocity;
}

float Player::getYVelocity() const {
    return yVelocity;
}

sf::Vector2f Player::getVelocity() const {
    return {xVelocity, yVelocity};
}

void Player::jump() {
    yVelocity = -12.0f;
    state = PlayerState::JUMPING;
}

void Player::moveLeft() {
    if (xVelocity > -5.0f) {
        xVelocity -= 1.0f;
        // Failed attempt at flipping player sprite
        // if (state == PlayerState::MOVING_RIGHT)
        //     sprite->scale(-1.0f, 1.0f);
        state = PlayerState::MOVING_LEFT;
    }
}

void Player::moveRight() {
    if (xVelocity < 5.0f) {
        xVelocity += 1.0f;
        // if (state == PlayerState::MOVING_LEFT)
        //     sprite->scale(-1.0f, 1.0f);
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
    if (sprite->getPosition().x < 0.0f) {
        sprite->setPosition(800.0f, sprite->getPosition().y);
    }
    else if (sprite->getPosition().x > 800.0f) {
        sprite->setPosition(0.0f, sprite->getPosition().y);
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

// sf::Vector2f Player::getCoordinates() const {
//     return sprite->getPosition();
// }

// void Player::setCoordinates(const sf::Vector2f& coordinates_) {
//     sprite->setPosition(coordinates_);
// }