#include "GameObject.h"

#include <iostream>

GameObject::GameObject() {
    std::cout << "GameObject constructor called\n";
}

GameObject::~GameObject() {
    std::cout << "GameObject destructor called\n";
}

GameObject::GameObject(const GameObject& gameObject) {
    std::cout << "GameObject copy constructor called\n";
    // texture = new sf::Texture();
    texture = gameObject.texture;
    sprite = sf::Sprite();
    sprite.setPosition(gameObject.sprite.getPosition());
    sprite.setTexture(*texture);
}

GameObject& GameObject::operator=(const GameObject& gameObject) {
    std::cout << "GameObject copy assignment operator called\n";
    if (this != &gameObject) {
        // texture = new sf::Texture();
        texture = gameObject.texture;
        sprite = sf::Sprite();
        sprite.setPosition(gameObject.sprite.getPosition());
        sprite.setTexture(*texture);
    }
    return *this;
}

void GameObject::assignTexture(sf::Texture& texture_) {
    texture = &texture_;
    sprite.setTexture(*texture);
}

void GameObject::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::Texture& GameObject::getTexture() {
    return *texture;
}

void GameObject::loadTexture(const std::string& path) {
    texture->loadFromFile(path);
    sprite.setTexture(*texture);
}

sf::Sprite GameObject::getSprite() const {
    return sprite;
}

void GameObject::setSpritePos(const sf::Vector2f& coordinates) {
    sprite.setPosition(coordinates);
}

void GameObject::setSpriteScale(const sf::Vector2f& scale) {
    sprite.setScale(scale);
}

void GameObject::setSpriteOrigin(const sf::Vector2f& origin) {
    sprite.setOrigin(origin);
}

void GameObject::moveSprite(const sf::Vector2f& coordinates_) {
    sprite.move(coordinates_);
}

void GameObject::setSpritePosition(const sf::Vector2f& coordinates) {
    sprite.setPosition(coordinates);
}
