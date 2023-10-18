#pragma once

#include <iostream>

class Coordinates {
private:
    int x;
    int y;
public:
    Coordinates();
    Coordinates(int x_, int y_);
    Coordinates(const Coordinates& coordinates_);
    Coordinates& operator=(const Coordinates& coordinates_);
    friend std::ostream& operator<<(std::ostream& os, const Coordinates& coordinates);
    void set(int x_, int y_);
    int getX() const;
    int getY() const;
};