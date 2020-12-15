#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"

class Buffer
{
public:
    Buffer(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~Buffer();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    Collision GetCollider() { return Collision(body); }

private:
    int row;
    sf::RectangleShape body;
    Animation animation;
};