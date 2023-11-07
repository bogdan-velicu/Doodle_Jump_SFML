#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    GameObject();
    virtual ~GameObject();
    virtual void assignTexture(sf::Texture& texture_);

    virtual sf::Texture& getTexture() {
        return texture;
    }

    virtual sf::Sprite getSprite() {
        return sprite;
    }

    virtual void draw(sf::RenderWindow& window, const sf::Sprite& sprite_);
};