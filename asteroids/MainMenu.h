#pragma once
#include <SFML\Graphics.hpp>
#include "Globals.h"
#include<iostream>
// @author: Jonelle Lawler, David Whiteford
class MainMenu
{
public:


	MainMenu();
	~MainMenu();
	void loadContent();


	// to be called in and drawn in the game 
	void create(sf::RenderWindow & m_window);
	

	sf::Texture menuTexture;
	sf::Sprite menuSprite;

private:

	
	
};
