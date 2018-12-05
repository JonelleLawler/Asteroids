#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>

// @author: Jonelle Lawler, David Whiteford
class gameOver
{
public:
	gameOver();
	~gameOver();

	void loadContent();

	void render(sf::RenderWindow & window , int score);
	
	void update();

	sf::Sprite gameOverSprite;
	sf::Texture gameOverTexture;
	sf::Text gameOverMsg;
	sf::Font font;

	

private:
};
