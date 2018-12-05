#include "Help.h"
// @author Jonelle Lawler, David Whiteford
Help::Help()
{
	loadContent();

	helpSprite.setTexture(helpTexture);
	helpSprite.setPosition(0,0);
	
}

Help::~Help()
{
}

void Help::loadContent()
{
	if (!helpTexture.loadFromFile("ASSETS//IMAGES//help.png"))
	{
		std::cout << "Error loading help screen image" << std::endl;
	}
}

void Help::update()
{
}

void Help::render(sf::RenderWindow & m_window)
{
	m_window.draw(helpSprite);
}
