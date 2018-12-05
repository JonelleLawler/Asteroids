#pragma once
#include "SplashScreen.h"
#include "Globals.h"
#include "Game.h"

// @author Jonelle Lawler, David Whiteford

SplashScreen::SplashScreen()
{
	loadContent();
	splashSprite.setTexture(splashTexture);
	splashSprite.setPosition(0, 0);

}

SplashScreen::~SplashScreen()
{

}



void SplashScreen::loadContent()
{
	if (!splashTexture.loadFromFile("ASSETS//IMAGES//splashScreen.png"))
	{
		std::cout << "Error loading splash screen background" << std::endl;
	}
}





void SplashScreen::render(sf::RenderWindow & window)
{
	window.draw(splashSprite);
}

void SplashScreen::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Game::currentState = gameModes::mainMenu;
	}

}
