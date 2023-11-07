#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
private:
    sf::Texture *texture = new sf::Texture();
    sf::Sprite sprite = sf::Sprite();
public:
    GameObject();
    virtual ~GameObject();
    GameObject(const GameObject& gameObject);
    GameObject& operator=(const GameObject& gameObject);
    virtual void draw(sf::RenderWindow& window);
    virtual void assignTexture(sf::Texture& texture_);
    virtual sf::Texture& getTexture();
    virtual void loadTexture(const std::string& path);
    virtual sf::Sprite getSprite() const;
    virtual void setSpritePos(const sf::Vector2f& coordinates);
    virtual void setSpriteScale(const sf::Vector2f& scale);
    virtual void setSpriteOrigin(const sf::Vector2f& origin);
    virtual void moveSprite(const sf::Vector2f& coordinates_);
    virtual void setSpritePosition(const sf::Vector2f& coordinates);
};