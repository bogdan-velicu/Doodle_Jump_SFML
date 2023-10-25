#include <SFML/Graphics.hpp>

enum class PlayerState {
    STANDING,
    JUMPING,
    FALLING,
    MOVING_LEFT,
    MOVING_RIGHT,
};

class Player {
private:
    sf::Texture texture = sf::Texture();
    PlayerState state = PlayerState::STANDING;
    sf::Sprite *sprite;
    float currentHeight;
    float xVelocity;
    float yVelocity;
public:
    Player();
    ~Player();
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    Player& operator=(const Player& player_);
    Player(const Player& player_);

    // sf::Vector2f getCoordinates() const;
    // void setCoordinates(const sf::Vector2f& coordinates_);

    // void setXVelocity(float xVelocity_);
    void setYVelocity(float yVelocity_);

    float getXVelocity() const;
    float getYVelocity() const;
    sf::Vector2f getVelocity() const;

    // sf::Texture getTexture() const;
    sf::Sprite getSprite() const;
    void moveSprite(const sf::Vector2f& coordinates_);

    void handleMovement();
    void update();
    void jump();
    void moveLeft();
    void moveRight();
};