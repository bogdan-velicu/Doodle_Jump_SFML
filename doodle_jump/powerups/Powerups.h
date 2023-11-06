#pragma once

#include "../game_object/GameObject.h"
#include <iostream>

enum class PowerupsType {
    ROCKET,
    SHIELD,
    JETPACK,
};
std::ostream& operator<<(std::ostream& out, const PowerupsType& powerupsType);

class Powerups : public GameObject {
private:
    sf::Texture *texture = new sf::Texture();
    sf::Sprite sprite = sf::Sprite();
    PowerupsType type;
    GameObject* gameObject;
    int updateCount;
public:
    Powerups();
    ~Powerups();
    void useGenerator(const sf::Vector2f& lastPlatformCoordinates);
    friend std::ostream& operator<<(std::ostream& os, const Powerups& powerups);
    PowerupsType getType() const;
    sf::Sprite getSprite() const;
    void assignTexture(sf::Texture& texture_);
    void setGameObject(GameObject* gameObject_);
    void moveSprite(const sf::Vector2f& coordinates_);
    void animateMovement();
    void draw(sf::RenderWindow& window, const sf::Sprite& sprite) override;
};