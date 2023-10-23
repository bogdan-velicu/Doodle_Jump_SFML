#include <iostream>
#include <SFML/Graphics.hpp>

enum class PlatformType {
    NORMAL,
    BREAKABLE,
    MOVING,
    BOOST,
};
std::ostream& operator<<(std::ostream& os, const PlatformType& platformType);

class Platform {
private:
    PlatformType type;
    sf::Texture texture;
    sf::Sprite* sprite;
public:
    Platform();
    explicit Platform(bool upperScreen);
    explicit Platform(PlatformType type_);
    friend std::ostream& operator<<(std::ostream& os, const Platform& platform);
    Platform& operator=(const Platform& platform_);
    Platform(const Platform& platform_) = default;
    ~Platform();
    PlatformType getType() const;
    sf::Sprite getSprite() const;
    sf::Texture getTexture() const;
    void moveSprite(const sf::Vector2f& coordinates_);
};