#include "Coordinates.h"

Coordinates::Coordinates() {
    x = 0;
    y = 0;
}

Coordinates::Coordinates(int x_, int y_) {
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

void Coordinates::set(int x_, int y_) {
    x = x_;
    y = y_;
}

int Coordinates::getX() const {
    return x;
}

int Coordinates::getY() const {
    return y;
}