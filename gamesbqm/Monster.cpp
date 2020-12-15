#include "Monster.h"
#include<iostream>

Monster::Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float h, float w, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->count = 0;
    this->count1 = 0;
    this->count2 = 0;
    row = 0;
    body.setSize(sf::Vector2f(h, w));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

Monster::~Monster()
{
}

void Monster::update1(float deltaTime, Bullet bullet1)
{
    animation.updateCoin(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (bullet1.GetCollider().CheckCollision(this->GetCollider()))
    {
        this->count++;
        row = 1;
        body.setPosition(-1000.0f, 350.0f);
    }
}

void Monster::update2(float deltaTime, Player player)
{

    if (abs(player.GetPosition().x - body.getPosition().x) <= 500.0f)
    {
        velocity.x = 150;
        velocity.y += 5000.0f * deltaTime;

        if (player.GetPosition().x < body.getPosition().x)
        {
            body.move(-velocity.x * deltaTime, velocity.y * deltaTime);
        }
        else if (player.GetCollider().CheckCollision(this->GetCollider()))
        {
            x1 += 10;
            body.setPosition(-100.0f, 350.0f);
        }
        animation.updateCoin(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }

}

/*void Enemy::updateamong1(float deltaTime, Bullet bullet1)
{

    animation.updatestar(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (bullet1.GetCollider().CheckCollision(this->GetCollider()))
    {
        this->count++;
        row = 1;
        body.setPosition(-1000.0f, 350.0f);
    }
}

void Enemy::updateamong2(float deltaTime, Player player)
{

    if (abs(player.GetPosition().x - body.getPosition().x) <= 500.0f)
    {
        velocity.x = 150;
        velocity.y += 5000.0f * deltaTime;

        if (player.GetPosition().x < body.getPosition().x)
        {
            body.move(-velocity.x * deltaTime, velocity.y * deltaTime);
        }
        else if (player.GetCollider().CheckCollision(this->GetCollider()))
        {
            x1 += 10;
            body.setPosition(-100.0f, 350.0f);
        }
        animation.updatestar(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }

}*/

void Monster::OnCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f) 
    {
        //left
        velocity.x = 0.0f;
    }
    else if (direction.x > 0.0f) 
    {
        //right
        velocity.x = 0.0f;
    }
    if (direction.y < 0.0f)
    {
        //bottom
        velocity.y = 0.0f;
    }
    else if (direction.y > 0.0f) 
    {
        //top
        velocity.y = 0.0f;
    }
}

void Monster::draw(sf::RenderWindow& window)
{
    window.draw(body);
}