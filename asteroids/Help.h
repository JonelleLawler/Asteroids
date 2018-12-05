#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

// @author: Jonelle Lawler, David Whiteford
class Help {

private:


public:


	Help();
	~Help();

	void loadContent();

	void update();

	void render(sf::RenderWindow & m_window);

	sf::Texture helpTexture;
	sf::Sprite helpSprite;

};