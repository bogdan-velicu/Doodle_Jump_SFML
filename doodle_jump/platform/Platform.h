#include <iostream>
#include <SFML/Graphics.hpp>

enum class PlatformType {
    NORMAL,
    BREAKABLE,
    MOVING,
    BOOST,
};
inline std::ostream& operator<<(std::ostream& os, const PlatformType& platformType) {
    switch (platformType) {
        case PlatformType::NORMAL:
            os << "NORMAL";
            break;
        case PlatformType::BREAKABLE:
            os << "BREAKABLE";
            break;
        case PlatformType::MOVING:
            os << "MOVING";
            break;
        case PlatformType::BOOST:
            os << "BOOST";
            break;
    }
    return os;
}

class Platform {
private:
    PlatformType type;
    sf::Sprite sprite;
public:
    Platform();
    explicit Platform(PlatformType type_);
    friend std::ostream& operator<<(std::ostream& os, const Platform& platform);
    Platform& operator=(const Platform& platform_);
    ~Platform();
    PlatformType getType() const;
    sf::Sprite getSprite() const;
};