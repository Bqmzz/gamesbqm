#include "Bullet.h"
#include<iostream>

Bullet::Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    body.setSize(sf::Vector2f(50.0f, 50.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(pos);
    body.setTexture(texture);
}

Bullet::~Bullet()
{
}

void Bullet::update(float deltaTime)
{
    if (body.getPosition().x != NULL - 10 && body.getPosition().y != NULL - 10) 
    {
        velocity.y = 0;
        velocity.x = speed * 5;
        body.move(velocity * deltaTime);
        animation.updateBullet(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }
}

void Bullet::update2(float deltaTime)
{
    velocity.x = speed * 5;
    velocity.y = 0;
    if (body.getPosition().x != NULL - 100 && body.getPosition().y != NULL - 100) 
    {
        body.move(velocity * deltaTime);
        animation.updateBullet(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }
}

void Bullet::attack(sf::Vector2f pos) {
    body.setPosition(pos.x + 53.0f, pos.y);
}

void Bullet::del()
{
    body.setPosition(NULL - 10, NULL - 10);
}

bool Bullet::isAvaliable() 
{
    isAva = true;
    return isAva;
}

void Bullet::draw(sf::RenderWindow& window)
{
    window.draw(body);
}