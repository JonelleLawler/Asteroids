#pragma once
#include "SFML/Graphics.hpp" 
#include "Bullets.h"
#include "Asteroids.h"
// @author: Jonelle Lawler, David Whiteford
class Player
{

private:



	float speed;
	int playerWidth;
	int playerHeight;
	int playerDirection;
	bool playerAlive;
	float slowDown;

public:


	sf::Sprite sprite;

	// Different direction images
	sf::Texture northPlayer;
	sf::Texture southPlayer;
	sf::Texture eastPlayer;
	sf::Texture westPlayer;

	Player();
	void loadContent();
	void setAlive(bool alive);
	bool getAlive();

	sf::Sprite getBody();
	void setPosition(int xPos, int yPos);
	void movement();
	float getSpeed();
	void setSpeed(float speed);
	void playerShooting(Bullet &aBullet);
};


