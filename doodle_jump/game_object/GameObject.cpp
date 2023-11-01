#include "GameObject.h"

#include <iostream>

GameObject::GameObject() {
    std::cout << "GameObject constructor called\n";
}

GameObject::~GameObject() {
    std::cout << "GameObject destructor called\n";
}

void GameObject::draw(sf::RenderWindow &window, const sf::Sprite& sprite) {
    window.draw(sprite);
}
