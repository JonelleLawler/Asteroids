#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

// @author: Jonelle Lawler, David Whiteford

class Asteroids
{
// private data members
private:
	float asteroidsSpeed{};
	
	bool iaAlive{};
	int  asteroidsDirection{};
	int dirTimer{};

// public functions
public:

	Asteroids();
	~Asteroids();

	void loadContent();
	sf::Sprite getBody();
	void setAlive(bool alive);
	bool getAlive();
	
	void render(sf::RenderWindow & m_window);

	bool asteroidAlive{ true };

	int asteroidDirection{};

	static const int MAX_ASTEROIDS{ 5 };

	sf::Sprite asteroidBody;
	sf::Texture m_asteroidTex;

	void setPosition(sf::Vector2f);

	sf::Vector2f getPosition(sf::Vector2f pos);

	void setSpeed(int speed);

	// direction functions 
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();


	void update();

	sf::Vector2f position{};
};


