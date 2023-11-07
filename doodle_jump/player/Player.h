#include <SFML/Graphics.hpp>

#include "../game_object/GameObject.h"

enum class PlayerState {
    STANDING,
    JUMPING,
    FALLING,
    MOVING_LEFT,
    MOVING_RIGHT,
};

class Player : public GameObject {
private:
    PlayerState state = PlayerState::MOVING_LEFT;
    float currentHeight;
    float xVelocity;
    float yVelocity;
    int health;
public:
    Player();
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    void setYVelocity(float yVelocity_);
    float getYVelocity() const;
    sf::Vector2f getVelocity() const;
    void setHealth(int health_);
    void handleMovement();
    void update();
    void jump();
    void moveLeft();
    void moveRight();
};