#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

// @author: Jonelle Lawler, David Whiteford
class Shop
{
public:
	Shop();
	~Shop();

	void loadContent();
	void render(sf::RenderWindow & m_window, int newMoney);

	void update(float speed, int currency, int bulletSpeed);

	

	int upgradeCost;
	int newCurrency;
	int newBulletSpeed;
	float getSpeed();

	int getCurrency();

	int getBulletSpeed();

	sf::Sprite shopSprite;
	sf::Texture shopTexture;
	sf::Text currencyMsg;
	sf::Text lackOfMoneyMsg;
	sf::Font font;

	float playerSpeed;

private:
};

