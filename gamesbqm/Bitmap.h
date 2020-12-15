#pragma once
#include<SFML/Graphics.hpp>
#include "Collision.h"

class Bitmap
{
public:
	Bitmap(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size);
	~Bitmap();

	void draw(sf::RenderWindow& window);
	Collision getCollider() { return Collision(body); }

private:
	sf::RectangleShape body;
};