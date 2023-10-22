#include "Coordinates.h"

Coordinates::Coordinates() {
    x = 0;
    y = 0;
}

Coordinates::Coordinates(float x_, float y_) {
    x = x_;
    y = y_;
}

Coordinates::Coordinates(const Coordinates& coordinates_) {
    x = coordinates_.x;
    y = coordinates_.y;
}

Coordinates& Coordinates::operator=(const Coordinates& coordinates_) = default;

std::ostream& operator<<(std::ostream& os, const Coordinates& coordinates) {
    os << "(" << coordinates.getX() << ", " << coordinates.getY() << ")";
    return os;
}

void Coordinates::set(float x_, float y_) {
    x = x_;
    y = y_;
}

float Coordinates::getX() const {
    return x;
}

float Coordinates::getY() const {
    return y;
}