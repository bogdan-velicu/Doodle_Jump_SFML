#include "Enemy.h"

Enemy::Enemy() : GameObject() {
    this->health = 100.0f;
    this->updateCount = 0;
}

Enemy::Enemy(const Enemy& enemy) : GameObject(enemy) {
    this->health = enemy.health;
    this->updateCount = enemy.updateCount;
}

std::ostream& operator<<(std::ostream& os, const Enemy& enemy) {
    os << "Enemy: " << ", health: " << enemy.health << ", updateCount: " << enemy.updateCount;
    return os;
}

float Enemy::getHealth() const {
    return this->health;
}

void Enemy::setHealth(float health) {
    this->health = health;
}

void Enemy::animateMovement() {
    this->updateCount++;
    if (this->updateCount == 100) {
        this->updateCount = 0;
        // moveSprite({0, 1});
    }
}