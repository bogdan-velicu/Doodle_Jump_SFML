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
    sf::Texture texture = sf::Texture();
    PlayerState state = PlayerState::MOVING_LEFT;
    sf::Sprite sprite = sf::Sprite();
    float currentHeight;
    float xVelocity;
    float yVelocity;
public:
    Player();
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    void setYVelocity(float yVelocity_);
    float getYVelocity() const;
    sf::Vector2f getVelocity() const;
    sf::Sprite getSprite() const;
    void setSpritePosition(const sf::Vector2f& coordinates_);
    void moveSprite(const sf::Vector2f& coordinates_);
    void handleMovement();
    void update();
    void jump();
    void moveLeft();
    void moveRight();

    void draw(sf::RenderWindow& window, const sf::Sprite& sprite) override;
};