#include "Platform.h"
#include <iostream>

Platform::Platform() {
    std::cout << "Platform constructor called\n";
    coordinates = Coordinates(0, 0);
    type = PlatformType::NORMAL;
}

Platform::Platform(const Coordinates& coordinates_) {
    std::cout << "Platform constructor called\n";
    coordinates = coordinates_;
    type = PlatformType::NORMAL;
}

Platform::Platform(const Coordinates& coordinates_, PlatformType type_) {
    std::cout << "Platform constructor called\n";
    coordinates = coordinates_;
    type = type_;
}

std::ostream& operator<<(std::ostream& os, const Platform& platform) {
    os << "Platform: coordinates = " << platform.coordinates << ", type = " << platform.type;
    return os;
}

Platform& Platform::operator=(const Platform& platform_) = default;

Platform::~Platform() {
    std::cout << "Platform destructor called\n";
}

Coordinates Platform::getCoordinates() const {
    return coordinates;
}

PlatformType Platform::getType() const {
    return type;
}