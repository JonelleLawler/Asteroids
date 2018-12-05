#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>

// @author: Jonelle Lawler, David Whiteford

class Collectibles
{

public: 

	Collectibles();

	~Collectibles();

	void setPosition();

	void loadContent();

	void render(sf::RenderWindow &);

	sf::Sprite getBody();

	sf::Texture collectibleOne;

	sf::Sprite collectibleSprite;

	

private:

	static const int TYPE_ONE = 1;
	int collectibleType{};

};