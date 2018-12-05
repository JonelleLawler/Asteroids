// @author: Jonelle Lawler, David Whiteford
#include "Alien.h"   // include enemy header file
#include "time.h"//include time

Alien::Alien()
{
	// variables fo the x and y pos
	int xPos = 700;
	int yPos = 400;
	//function call to set position
	setPosition(xPos, yPos);
	//variables for direction, array speed, normal speed, random direction
	arraySpeed = 3;
	speed = 3;
	randDirection = rand() % 8 + 1 ;
	alienSprite.setScale(0.4, 0.4);

	//varaibles for timer and bool for alive
	dirTimer = 0;
	bool isAlive = true;

	alienLoad();
	alienSprite.setTexture(textureN);
}
void Alien::alienLoad()
{
	//loads the textures for enemy 
	if (!textureN.loadFromFile("ASSETS//IMAGES//alien2.png"))
	{
		std::cout << "Error loading alien image" << std::endl;
	}
	if (!textureS.loadFromFile("ASSETS//IMAGES//alien2.png"))
	{
		std::cout << "Error loading alien image" << std::endl;
	}
	if (!textureE.loadFromFile("ASSETS//IMAGES//alien2.png"))
	{
		std::cout << "Error loading alien image" << std::endl;
	}
	if (!textureW.loadFromFile("ASSETS//IMAGES//alien2.png"))
	{
		std::cout << "Error loading alien image" << std::endl;
	}
	if (!textureNE.loadFromFile("ASSETS//IMAGES//alien2.png"))
	{
		std::cout << "Error loading alien image" << std::endl;
	}
	if (!textureSE.loadFromFile("ASSETS//IMAGES//alien2.png"))
	{
		std::cout << "Error loading alien image" << std::endl;
	}
	if (!textureNW.loadFromFile("ASSETS//IMAGES//alien2.png"))
	{
		std::cout << "Error loading alien image" << std::endl;
	}
	if (!textureSW.loadFromFile("ASSETS//IMAGES//alien2.png"))
	{
		std::cout << "Error loading alien image" << std::endl;
	}

	

}
void Alien::deathSprite()
{
	alienSprite.setTexture(explosionTexture);
}
sf::Sprite Alien::enemyBody()
{
	//returns the alien sprite
	return alienSprite;
}

//sets the x and y pos of the enemy
void Alien::setPosition(int xPos, int yPos)
{
	alienSprite.setPosition(xPos, yPos);
}

// get the enemys sprite body
sf::Sprite Alien::getBody()
{
	//returns enemy prite
	return alienSprite;
}

void Alien::setAlive(bool aAlive)
{
	//function to set the enemy alive
	isAlive = aAlive;

}


bool Alien::getAlive()
{
	//returns if the enemy is alive
	return isAlive;
}
int Alien::getSpeed()
{
	return arraySpeed;
}


void Alien::arrayMovement()
//function to move array of enemies
{
	//gets the pos of the enemies 
	sf::Vector2f pos = alienSprite.getPosition();

	// NORTH MOVEMENT
	if (randDirection == 1)
	{
		
		pos.y = pos.y - arraySpeed;
		if (pos.y <= 0)
		{
			pos.y = pos.y + arraySpeed;
		}

		alienSprite.setTexture(textureN);

	}

	// SOUTH MOVEMENT
	if (randDirection == 2)
	{

		//adds speed to y pos and sets its texture
		pos.y = pos.y + arraySpeed;
		alienSprite.setTexture(textureS);

	}


	// WEST MOVEMENT
	if (randDirection == 3)
	{

		//subs speed from x pos and sets its texture
		pos.x = pos.x - arraySpeed;
		alienSprite.setTexture(textureW);

	}
	
	// EAST MOVEMENT
	if (randDirection == 4)
	{
		//adds speed to x pos and sets its texture
		pos.x = pos.x + arraySpeed;
		alienSprite.setTexture(textureE);
	}

	// SOUTH EAST MOVEMENT
	if (randDirection == 5)
	{
		pos.x = pos.x + arraySpeed;
		pos.y = pos.y + arraySpeed;
		alienSprite.setTexture(textureSE);
	}

	// SOUTH WEST MOVEMENT
	if (randDirection == 6)
	{
		pos.x = pos.x - arraySpeed;
		pos.y = pos.y + arraySpeed;
		alienSprite.setTexture(textureSW);
	}

	// NORTH EAST MOVEMENT 
	if (randDirection == 7)
	{
		pos.x = pos.x + arraySpeed;
		pos.y = pos.y - arraySpeed;
		alienSprite.setTexture(textureNE);
	}

	// NORTH WEST MOVEMENT 
	if (randDirection == 8)
	{
		pos.x = pos.x -  arraySpeed;
		pos.y = pos.y - arraySpeed;
		alienSprite.setTexture(textureNW);
	}

	////checks the emeies boundry collision for the x coordinates 
	if (pos.x <= 50)
	{
		pos.x = pos.x + arraySpeed;
	}
	if (pos.x + 100 >= 750)
	{
		pos.x = pos.x - arraySpeed;
	}
	//checks the emeies boundry collision for the y coordinates 
	if (pos.y <= 50)
	{
		pos.y = pos.y + arraySpeed;
	}

	if (pos.y + 100 >= 550)
	{
		pos.y = pos.y - arraySpeed;
	}
	//sets the new position of the array of enemies
	alienSprite.setPosition(pos);
}

void Alien::arrayDirection()
//function to get random direction 
{
	//adds one to the direction timer
	dirTimer += 1;
	//if the timer is less than 120
	if (dirTimer >= 110)
	{
		//produce an random number for the direction
		randDirection = rand() % 8 + 1;
		//reset timer to 0
		dirTimer = 0;
	}
}

bool Alien::arrayAlive()
{
	//function to return alive for the array
	return arrIsAlive;
}

void Alien::arrayAlive(bool arrAlive)
{
	//function to set alive
	arrIsAlive = arrAlive;

}

void Alien::render(sf::RenderWindow & m_window)
{
	m_window.draw(alienSprite);
}
int Alien::getDirection()
{
	//returns the rand direction
	return randDirection;
}
void Alien::collisionCheck()
{
	sf::Vector2f pos(alienSprite.getPosition());
		//checks if enemy is heading north
	if (randDirection == 1)
	{
		pos.y = pos.y + arraySpeed;
	}
	if (randDirection == 2)
	{
		//adds speed to y pos and sets its texture
		pos.y = pos.y - arraySpeed;
	}
	// CHECKS WEST MOVEMENT
	if (randDirection == 3)
	{
		//subs speed from x pos and sets its texture
		pos.x = pos.x + arraySpeed;
	}
	// CHECKS EAST MOVEMENT
	if (randDirection == 4)
	{
		//adds speed to x pos and sets its texture
		pos.x = pos.x - arraySpeed;
		
	}
	// CHECKS SOUTH EAST MOVEMENT
	if (randDirection == 5)
	{
		pos.x = pos.x - arraySpeed;
		pos.y = pos.y - arraySpeed;
		
	}
	// CHECKS SOUTH WEST MOVEMENT
	if (randDirection == 6)
	{
		pos.x = pos.x + arraySpeed;
		pos.y = pos.y - arraySpeed;

	}
	// CHECKS NORTH EAST MOVEMENT 
	if (randDirection == 7)
	{
		pos.x = pos.x - arraySpeed;
		pos.y = pos.y + arraySpeed;
		
	}
	// CHECKS NORTH WEST MOVEMENT 
	if (randDirection == 8)
	{
		pos.x = pos.x + arraySpeed;
		pos.y = pos.y + arraySpeed;
	}
}