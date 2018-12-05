#pragma once
#include "SFML/Graphics.hpp"
/// <summary>
/// @author: Jonelle Lawler, David Whiteford
/// </summary>
class Bullet
{
private:
	int bulletSpeed;
	int speed;
	int theDirection{};
	bool isAlive{ false };
	float slowDown;
	// directions
	const int NORTH{ 1 };
	const int SOUTH{ 2 };
	const int EAST{ 3 };
	const int WEST{ 4 };




public:

	Bullet();
	void load();
	sf::Sprite bulletSprite;
	sf::Texture bulletTextureN;
	sf::Texture bulletTextureS;
	sf::Texture bulletTextureW;
	sf::Texture bulletTextureE;
	sf::Sprite getBody();
	void setAlive();
	void setDirection(int aDir);
	void setAlive(bool aAlive);
	bool getAlive();
	

	void movement();

	int getSpeed();

	void setSpeed(int speed);

};

