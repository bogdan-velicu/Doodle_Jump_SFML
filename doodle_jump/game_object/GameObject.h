#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    GameObject();
    virtual ~GameObject();
    virtual void draw(sf::RenderWindow& window, const sf::Sprite& sprite);
};