#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"

class Coin
{
public:
    Coin(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~Coin();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    int iscollide()
    {
        if (Coins == 1) {
            Coins--;
            return 1;
        }
    }

    Collision GetCollider() { return Collision(body); }

private:
    int row;
    int Coins;
    int collide;
    sf::RectangleShape body;
    Animation animation;
};