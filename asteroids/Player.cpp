#include "Player.h"


// @author: Jonelle Lawler, David Whiteford


Player::Player()
{

	loadContent();
	int xPos = 50;
	int yPos = 50;
	int playerWidth = 250;
	int playerHeight = 170;
	playerDirection = 1;
	playerAlive = true;
	setPosition(xPos, yPos);
	speed = 2;
	
	sprite.setScale(0.4, 0.4);
	sprite.setTexture(northPlayer);
}
void Player::loadContent()
{
	if (!northPlayer.loadFromFile("ASSETS//IMAGES//upPlayer.png"))
	{
		std::cout << "Error loading north facing player" << std::endl;
	}
	if (!southPlayer.loadFromFile("ASSETS//IMAGES//downPlayer.png"))
	{
		std::cout << "Error loading south facing player" << std::endl;
	}
	if (!eastPlayer.loadFromFile("ASSETS//IMAGES//rightPlayer.png"))
	{
		std::cout << "Error loading east facing player" << std::endl;
	}
	if (!westPlayer.loadFromFile("ASSETS//IMAGES//leftPlayer.png"))
	{
		std::cout << "Error loading west facing player" << std::endl;
	}

}
void Player::setAlive(bool alive)
{
	playerAlive = alive;
}
bool Player::getAlive()
{
	return playerAlive;
}

void Player::setPosition(int xPos, int yPos)
{
	sprite.setPosition(xPos, yPos);
	sprite.setOrigin(xPos + 100, yPos + 100);
}

sf::Sprite Player::getBody()
{
	return sprite;
}

//returns speed
void Player::setSpeed(float newSpeed)
{
	speed = newSpeed;
}
float Player::getSpeed()
{
	return speed;
}
void Player::playerShooting(Bullet &aBullet)
{
	//get pos of the player
	sf::Vector2f pos(sprite.getPosition());
	//sets the bullet direction equal to player direction 
	aBullet.setDirection(playerDirection);
	//sets the bullet to alive
	aBullet.setAlive(true);
	//sets the bullet position equal to player position
	aBullet.bulletSprite.setPosition(pos.x - 13, pos.y - 13 );
}

void Player::movement()
{
	//movement of the player
	//gets the pos of the player
	sf::Vector2f pos(sprite.getPosition());
	//checks the key press for w and up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (pos.y  >= 55)
		{
			//moves y pos and  sets pos and the direction 
			pos.y = pos.y - speed ;
			sprite.setPosition(pos);
			playerDirection = 1;
			sprite.setTexture(northPlayer);
		}
		

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (pos.x >= 55)
		{
			//moves x pos and  sets pos and the direction 
			pos.x = pos.x - speed ;
			sprite.setPosition(pos);
			playerDirection = 3;
			sprite.setTexture(westPlayer);
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (pos.y + 12 <= 600)
		{
			//moves y pos and  sets pos and the direction 
			pos.y = pos.y + speed ;
			sprite.setPosition(pos);
			playerDirection = 2;
			sprite.setTexture(southPlayer);
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (pos.x + 12 <= 800)
		{
			//moves x pos and  sets pos and the direction 
			pos.x = pos.x + speed ;
			sprite.setPosition(pos);
			playerDirection = 4;
			sprite.setTexture(eastPlayer);
			
		}


	}
}
