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
    PowerupsType type;
    int updateCount;
public:
    Powerups();
    ~Powerups() override;
    void useGenerator(const sf::Vector2f& lastPlatformCoordinates);
    friend std::ostream& operator<<(std::ostream& os, const Powerups& powerups);
    Powerups& operator=(const Powerups& powerups);
    Powerups(const Powerups& powerups);
    PowerupsType getType() const;
    // sf::Sprite getSprite() const;
    // void assignTexture(sf::Texture& texture_);
    // void setGameObject(GameObject* gameObject_);
    // void animateMovement();
};