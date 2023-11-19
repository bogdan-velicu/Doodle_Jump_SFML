#include "../game_object/GameObject.h"
#include <iostream>

class Enemy : public GameObject {
    private:
        float health;
        int updateCount;
    public:
        Enemy();
        Enemy(const Enemy& enemy);
        Enemy& operator=(const Enemy& enemy) = default;
        friend std::ostream& operator<<(std::ostream& os, const Enemy& enemy);
        float getHealth() const;
        void setHealth(float health);
        void animateMovement();
};