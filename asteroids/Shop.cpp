#pragma once
#include "Game.h"

#include "Globals.h"
#include "Shop.h"

// @author Jonelle Lawler, David Whiteford

Shop::Shop()
{
	loadContent();
	shopSprite.setTexture(shopTexture);
	shopSprite.setPosition(0, 0);
	playerSpeed = 0;
	upgradeCost = 0;
	newCurrency = 0;
	newBulletSpeed = 0;
}
Shop::~Shop()
{

}
void Shop::loadContent()
{
	if (!shopTexture.loadFromFile("ASSETS//IMAGES//shop.png"))
	{
		std::cout << "Error loading splash screen shop" << std::endl;
	}
	if (!font.loadFromFile("ASSETS/FONTS/ariblk.ttf"))
	{
		std::cout << "error with font file file";
	}
	// set up the message string score
	currencyMsg.setFont(font);  // set the font for the text    
	currencyMsg.setCharacterSize(48); // set the text size
	currencyMsg.setFillColor(sf::Color::Red); // set the text colour
	currencyMsg.setPosition(20, 520);  // its position on the screen
	
	
}
void Shop::render(sf::RenderWindow &m_window, int newMoney)
{
	currencyMsg.setString(" Money : " + std::to_string(newMoney));
	m_window.draw(shopSprite);
	m_window.draw(currencyMsg);
	m_window.draw(lackOfMoneyMsg);
	

	
}

void Shop::update(float speed , int currency , int bulletSpeed )
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		Game::currentState = gameModes::mainMenu;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		newCurrency = currency - 100;
		playerSpeed = speed + 0.3;
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		newBulletSpeed = bulletSpeed + 1;
		newCurrency = currency - 100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		
	}

}
//returns new player speed
float Shop::getSpeed()
{
	return playerSpeed;
}
int Shop::getCurrency()
{
	return newCurrency;
}
int Shop::getBulletSpeed()
{
	return newBulletSpeed;
}