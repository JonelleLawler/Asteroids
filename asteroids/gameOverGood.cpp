#pragma once
#include "Game.h"
#include "Globals.h"
#include "gameOverGood.h"
// @author Jonelle Lawler, David Whiteford
gameOverGood::gameOverGood()
{
	loadContent();
	gameOverSprite.setTexture(gameOverTexture);
	gameOverSprite.setPosition(0, 0);

}
gameOverGood::~gameOverGood()
{

}
void gameOverGood::loadContent()
{
	if (!gameOverTexture.loadFromFile("ASSETS//IMAGES//gameOverScreenGood.png"))
	{
		std::cout << "Error loading splash screen game over" << std::endl;
	}
	if (!font.loadFromFile("ASSETS/FONTS/ariblk.ttf"))
	{
		std::cout << "error with font file file";
	}
	// set up the message string score
	gameOverMsg.setFont(font);  // set the font for the text    
	gameOverMsg.setCharacterSize(48); // set the text size
	gameOverMsg.setFillColor(sf::Color::Red); // set the text colour
	gameOverMsg.setPosition(10, 450);  // its position on the screen
}
void gameOverGood::render(sf::RenderWindow & window, int score)
{
	window.draw(gameOverSprite);
	window.draw(gameOverMsg);
	gameOverMsg.setString(" Game Over Score : " + std::to_string(score));
}

void gameOverGood::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Game::currentState = gameModes::mainMenu;

	}

}