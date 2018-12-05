#pragma once 
#include "Collectibles.h"

// @author: Jonelle Lawler, David Whiteford
Collectibles::Collectibles()
{
	loadContent();
	collectibleType = TYPE_ONE;
	collectibleSprite.setTexture(collectibleOne);
	setPosition();
}
Collectibles::~Collectibles()
{

}
void Collectibles::setPosition()
{
	collectibleSprite.setPosition(400, 300);
}
void Collectibles::loadContent()
{
	if (!collectibleOne.loadFromFile("ASSETS//IMAGES//gems.png"))
	{
		std::cout << "Error loading collectible image" << std::endl;
	}


}
void Collectibles::render(sf::RenderWindow &window)
{
	window.draw(collectibleSprite);
}
sf::Sprite Collectibles::getBody()
{
	return collectibleSprite;
}