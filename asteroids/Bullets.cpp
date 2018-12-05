#include "Bullets.h"
#include "Player.h"
/// <summary>
/// @author: Jonelle Lawler, David Whiteford
/// </summary>
Bullet::Bullet()
{

	load(); 
	isAlive = false;
	//bullet variables 
	speed = 5;
	bulletSpeed = 8;

	//sets the bullet sprite to texture north
	bulletSprite.setTexture(bulletTextureN);

}

void Bullet::load()
{
	if (!bulletTextureN.loadFromFile("ASSETS/IMAGES/bullet_blaster_small_singleN.png"))
	{
		std::cout << "Error loading north facing bullet" << std::endl;
	}
	if (!bulletTextureS.loadFromFile("ASSETS/IMAGES/bullet_blaster_small_singleS.png"))
	{
		std::cout << "Error loading north facing bullet" << std::endl;
	}
	
	if (!bulletTextureE.loadFromFile("ASSETS/IMAGES/bullet_blaster_small_singleE.png"))
	{
		std::cout << "Error loading north facing bullet" << std::endl;
	}
	
	if (!bulletTextureW.loadFromFile("ASSETS/IMAGES/bullet_blaster_small_singleW.png"))
	{
		std::cout << "Error loading north facing bullet" << std::endl;
	
	}
	
}

// returns the sprite 
sf::Sprite Bullet::getBody()
{
	return bulletSprite;
}


// determine whether or not the bullet is active
void Bullet::setDirection(int aDir)
{
	
	//sets bullet direction equal to player direction
	theDirection = aDir;
}

void Bullet::setAlive(bool aAlive)
{
	//sets the bullet to whether is alive or not 
	isAlive = aAlive;

}

bool Bullet::getAlive()
{
	//returns the value for whether its alive
	return isAlive;
}
int Bullet::getSpeed()
{
	return bulletSpeed;
}
void Bullet::setSpeed(int speed)
{
	bulletSpeed = speed;
}

void Bullet::movement()
{
	//creates a variable pos for the position of the bullet
	sf::Vector2f pos = bulletSprite.getPosition();
	
		//checks if the bullet is alive
		if (isAlive == true)
		{
			//checks the direction
			if (theDirection == 1)
			{
				pos.y = pos.y - bulletSpeed;
				bulletSprite.setTexture(bulletTextureN);

				if (pos.y <= 0)
				{
					//sets alive to false
					isAlive = false;
				}
			}
			//checks the direction
			else if (theDirection == 2)
			{
				pos.y = pos.y + bulletSpeed;
				bulletSprite.setTexture(bulletTextureS);

				if (pos.y >= 600)
				{
					//sets alive to false
					isAlive = false;
				}
			}
			//checks the direction
			else if (theDirection == 4)
			{
				pos.x = pos.x + bulletSpeed;
				bulletSprite.setTexture(bulletTextureE);

				if (pos.x > 800)
				{
					//sets alive to false
					isAlive = false;
				}
			}
			//checks the direction
			else if (theDirection == 3)
			{
				pos.x = pos.x - bulletSpeed;
				bulletSprite.setTexture(bulletTextureW);

				if (pos.x <= 0)
				{
					//sets alive to false
					isAlive = false;
				}
			}
			//sets the pos of the bullet
			bulletSprite.setPosition(pos);
		}
}
