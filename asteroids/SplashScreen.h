#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
// @author: Jonelle Lawler, David Whiteford

class SplashScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void loadContent();

	void render(sf::RenderWindow & window);

	void update();

	sf::Sprite splashSprite;
	sf::Texture splashTexture;

private:
};