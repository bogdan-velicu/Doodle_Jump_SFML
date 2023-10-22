#include <SFML/Graphics.hpp>

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    float xVelocity;
    float yVelocity;
public:
    Player();
    ~Player();
    friend std::ostream& operator<<(std::ostream& out, const Player& player);

    sf::Vector2f getCoordinates() const;
    void setCoordinates(const sf::Vector2f& coordinates_);

    sf::Texture getTexture() const;
    sf::Sprite getSprite() const;

    void handleMovement();
    void update();
    void jump();
    void moveLeft();
    void moveRight();
};