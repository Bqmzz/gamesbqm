#include "Coin.h"
#include<iostream>

Coin::Coin(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
	animation(texture, imageCount, switchTime)
{
	Coins = 0;
	collide = 0;
	row = 0;
	body.setSize(sf::Vector2f(35.0f, 44.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(x, y);
	body.setTexture(texture);
}

Coin::~Coin()
{
}

void Coin::update(float deltaTime)
{
	animation.updateCoin(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void Coin::draw(sf::RenderWindow& window)
{
	window.draw(body);
}