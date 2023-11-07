#include "GameObject.h"

#include <iostream>

GameObject::GameObject() {
    std::cout << "GameObject constructor called\n";
}

GameObject::~GameObject() {
    std::cout << "GameObject destructor called\n";
}

void GameObject::assignTexture(sf::Texture& texture_) {
    texture = texture_;
    sprite.setTexture(texture);
}

void GameObject::draw(sf::RenderWindow &window, const sf::Sprite& sprite_) {
    window.draw(sprite_);
}
