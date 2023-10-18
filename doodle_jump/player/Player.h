#include "./../coordinates/Coordinates.h"


class Player {
private:
    Coordinates coordinates;
public:
    Player();
    explicit Player(const Coordinates& coordinates_);
    ~Player();
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    Coordinates getCoordinates() const;
    void jump();
    void moveLeft();
    void moveRight();
    void update();
    void draw();
};