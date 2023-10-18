#include "./../coordinates/Coordinates.h"
#include <iostream>

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
    Coordinates coordinates;
    PlatformType type;
public:
    Platform();
    explicit Platform(const Coordinates& coordinates_);
    explicit Platform(const Coordinates& coordinates_, PlatformType type_);
    friend std::ostream& operator<<(std::ostream& os, const Platform& platform);
    Platform& operator=(const Platform& platform_);
    ~Platform();
    Coordinates getCoordinates() const;
    PlatformType getType() const;
    void update();
    void draw();
};