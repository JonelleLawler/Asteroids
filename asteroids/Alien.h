#pragma once
// @author: Jonelle Lawler, David Whiteford


// enemy class declaration

#include "SFML/Graphics.hpp" 
#include<iostream>


class Alien
{
	// private data members


public:
	//loads the sprites and the texture for each direction
	sf::Sprite alienSprite;
	sf::Texture bulletTexture;
	sf::Texture textureS;
	sf::Texture textureE;
	sf::Texture textureW;
	sf::Texture textureN;
	// diagonal direction sprites
	sf::Texture textureSE;
	sf::Texture textureNE;
	sf::Texture textureNW;
	sf::Texture textureSW;
	sf::Texture explosionTexture;


private:
	//data members for speed ,array speed, is the enemy and enemy array alive and direction timer and random direction
	int speed;
	int arraySpeed;
	int direction;
	bool isAlive;
	bool arrIsAlive;
	int dirTimer;
	int randDirection;
	
public:

	Alien();// default constructor
			//function to get the body of the enemy
	sf::Sprite getBody();
	//functions to move the enemy 
	
	//function to load enemy textures
	void alienLoad();

	void deathSprite();
	
	//function to run direction timer
	
	//function to move array
	void arrayMovement();
	//function to set direction of array and to get if its alive, get if its alive for both enemy and enemy array 
	void arrayDirection();
	bool getAlive();
	int getSpeed();
	void setAlive(bool aAlive);
	bool arrayAlive();
	void arrayAlive(bool arrAlive);
	sf::Sprite enemyBody();

	void render(sf::RenderWindow & m_window);

	int getDirection();

	void collisionCheck();

	//fuction to set the enemy position
	void setPosition(int xPos, int yPos);
	//function to check boundries of enemy
	bool touchingEdge = true;

};
