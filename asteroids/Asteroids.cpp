// @author: Jonelle Lawler, David Whiteford
#pragma once 
#include "Asteroids.h"
Asteroids::Asteroids()
{
	position = sf::Vector2f(rand() % 690 + 1, rand() % 250 + 300);
	asteroidDirection = rand() % 4 + 1;
	loadContent();
	asteroidBody.setTexture(m_asteroidTex);
	asteroidBody.setScale(0.5, 0.5);
}

Asteroids::~Asteroids()
{

}

void Asteroids::loadContent()
{
	if (!m_asteroidTex.loadFromFile("ASSETS//IMAGES//asteroid2.png"))
	{
		std::cout << "Error loading asteroid texture" << std::endl;
	}
}
sf::Sprite Asteroids::getBody()
{
	return asteroidBody;
	
}
void Asteroids::setAlive(bool alive)
{
	asteroidAlive = alive;
}
bool Asteroids::getAlive()
{
	return asteroidAlive;
}
void Asteroids::setPosition(sf::Vector2f pos)
{
	position = pos;

}

sf::Vector2f Asteroids::getPosition(sf::Vector2f pos)
{
	pos = position;
	return position;
}
void Asteroids::setSpeed(int speed)
{
	asteroidsSpeed = speed;

}
void Asteroids::moveNorth()
{
	position.y--;
	if (position.y <= 50)
	{
		position.y = 50;
		asteroidDirection = 2;
		asteroidBody.rotate(50);
	}
	asteroidBody.setPosition(position);
	asteroidBody.rotate(3);
}

void Asteroids::moveSouth()
{
	position.y++;
	if (position.y >= 550)
	{
		position.y = 550;
		asteroidDirection = 1 ;
		
	}

	asteroidBody.setPosition(position);
	asteroidBody.rotate(2);
}

void Asteroids::moveEast()
{
	position.x++;

	if (position.x >= 750)
	{
		position.x >= 750;
		asteroidDirection = 4;
		
	}
	asteroidBody.setPosition(position);
	asteroidBody.rotate(-1);
}

void Asteroids::moveWest()
{
	position.x--;

	if (position.x <= 50)
	{
		position.x = 50;
		asteroidDirection = 3;
		
	}
	asteroidBody.setPosition(position);
	asteroidBody.rotate(1);
}

void Asteroids::update()
{

	if (asteroidDirection == 1)
	{
		moveNorth();
	
	}
	if (asteroidDirection == 2)
	{
		moveSouth();
	}
	if (asteroidDirection == 3)
	{
		moveEast();
	}
	if (asteroidDirection == 4)
	{
		moveWest();
	}
}
void Asteroids::render(sf::RenderWindow & m_window)
{

	m_window.draw(asteroidBody);
}
