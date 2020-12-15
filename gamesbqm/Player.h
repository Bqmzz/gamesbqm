#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "Collision.h"
#include "Coin.h"
#include "Buffer.h"

#pragma once
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	sf::Sound Soundss;
	sf::SoundBuffer soundCoin;
	void update(float deltaTime, std::vector<Coin*>& stars, std::vector<Buffer>& X2Vector);
	void updateNumCoin(float deltaTime, std::vector<Coin*>& stars, std::vector<Buffer>& X2Vector);

	int getNumCoin() 
	{ 
		return this->numcoiny; 
	}
	int EndGameover() 
	{ 
		return int(body.getPosition().x - 200); 
	}
	bool getBuffStatus() 
	{ 
		return this->buffX10; 
	}
	bool soundStatus() 
	{ 
		return this->sound; 
	}

	void Draw(sf::RenderWindow& window);
	void ResetNumstar();
	void OnCollision(sf::Vector2f direction);
	int  getcheck() 
	{ 
		return this->check; 
	}
	void HPbar(float deltaTime, Player player, sf::Vector2f pos);
	void SetPosition(float x, float y);
	void RESET();
	int jumping() 
	{
		if (checkjump == 1) 
		{
			checkjump--;
		}
		return 1;
	}
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collision GetCollider() { return Collision(body); }

private:

	int numcoiny;
	int checkjump;
	float speed;
	float damage;
	bool sound;
	bool slide;
	bool bullet;
	bool buffX10;
	int check = 0;
	unsigned int row;

	sf::RectangleShape body;
	Animation animation;

	float buffTimer = 0;
	sf::Clock clock;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};