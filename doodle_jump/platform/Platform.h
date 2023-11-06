#pragma once

#include "../game_object/GameObject.h"
#include <iostream>
#include <SFML/Graphics.hpp>

enum class PlatformType {
    NORMAL,
    BREAKABLE,
    MOVING,
    BOOST,
};
std::ostream& operator<<(std::ostream& os, const PlatformType& platformType);

class Platform : public GameObject {
private:
    PlatformType type;
    sf::Texture *texture = new sf::Texture();
    sf::Sprite sprite = sf::Sprite();
    int updateCount;
public:
    Platform();
    ~Platform();
    Platform(const Platform& platform);
    Platform& operator=(const Platform& platform);
    void useGenerator(const sf::Vector2f& lastPlatformCoordinates);
    friend std::ostream& operator<<(std::ostream& os, const Platform& platform);
    PlatformType getType() const;
    sf::Sprite getSprite() const;
    void moveSprite(const sf::Vector2f& coordinates_);
    void animateMovement();
    void assignTexture(sf::Texture& texture_);
    void draw(sf::RenderWindow& window, const sf::Sprite& sprite) override;
};