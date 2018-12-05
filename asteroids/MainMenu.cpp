// @author Jonelle Lawler, David Whiteford
#include"MainMenu.h"
MainMenu::MainMenu()
{
	loadContent();
	menuSprite.setTexture(menuTexture);
	menuSprite.setPosition(0, 0); 
}

MainMenu::~MainMenu()
{
}

void MainMenu::loadContent()
{
	if (!menuTexture.loadFromFile("ASSETS//IMAGES//MainMenu.png"))
	{
		std::cout << "Error loading main menu image" << std::endl;
	}
}




void MainMenu::create(sf::RenderWindow & m_window)
{
	m_window.draw(menuSprite);
}


