#pragma once

#include <iostream>

class Coordinates {
private:
    float x;
    float y;
public:
    Coordinates();
    Coordinates(float x_, float y_);
    Coordinates(const Coordinates& coordinates_);
    Coordinates& operator=(const Coordinates& coordinates_);
    friend std::ostream& operator<<(std::ostream& os, const Coordinates& coordinates);
    void set(float x_, float y_);
    float getX() const;
    float getY() const;
};