#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collision.h"
#include "Bullet.h"

class Monster
{
public:
    Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float h, float w, float x, float y);
    ~Monster();

    void update1(float deltaTime, Bullet bullet1);
    void update2(float deltaTime, Player player);
    //void updateamong1(float deltaTime, Bullet bullet1);
    //void updateamong2(float deltaTime, Player player);
    void draw(sf::RenderWindow& window);
    void OnCollision(sf::Vector2f direction);
    Collision GetCollider() { return Collision(body); }

    int hit1()
    {
        if (count == 1) 
        {
            count--;
            return 1;
        }
    }

    int colAlien()
    {
        if (x1 == 10) 
        {
            x1 -= 10;
            return 2;
        }
    }

private:
    int row;
    int count;
    int count1;
    int count2;
    int x1 = 0;
    float speed;

    sf::RectangleShape body;
    Animation animation;
    sf::Vector2f velocity;
    sf::Sprite Drawalien;
};