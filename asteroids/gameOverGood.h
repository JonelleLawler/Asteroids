#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>

// @author: Jonelle Lawler, David Whiteford
class gameOverGood
{
public:
	gameOverGood();
	~gameOverGood();

	void loadContent();

	void render(sf::RenderWindow & window, int score);

	void update();

	sf::Sprite gameOverSprite;
	sf::Texture gameOverTexture;
	sf::Text gameOverMsg;
	sf::Font font;



private:
};

