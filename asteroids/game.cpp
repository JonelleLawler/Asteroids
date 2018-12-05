/// <summary>
/// @author: Jonelle Lawler, David Whiteford
/// Submission Date: 27/04/2018 
/// 
/// 
/// ISSUES:
/// 1. Sound effects 
/// 2. Had to use boolean in main menu class to then use to switch game mode as I has circular dependencies going on (googled my error), assuming that isn't very efficient? 
/// game class required main menu header, main menu required game header 
/// </summary>

#include "Game.h"


// We want to start at the splash screen 
gameModes Game::currentState = gameModes::splashMode;

Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Asteroids" },
	m_exitGame{ false } //when true game will exit

{


	loadContent();

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		//loads bullet array
		bulletArray[i].load();
	}


	playMusic();
	
	backgroundSprite.setTexture(backgroundImage);

	// This is in default constructor as we start on splash screen 
	if (gameModes::splashMode == currentState)
	{
		splash.render(m_window);
	}


}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}



void Game::loadContent()
{

	// IMAGES

	if (!backgroundImage.loadFromFile("ASSETS//IMAGES//backgroundGame.png"))
	{
		std::cout << "Error loading background image";
	}
	if (!font.loadFromFile("ASSETS/FONTS/ariblk.ttf"))
	{
		std::cout << "error with font file file";
	}



	// set up the message string score
	livesMsg.setFont(font);  // set the font for the text    
	livesMsg.setCharacterSize(24); // set the text size
	livesMsg.setFillColor(sf::Color::White); // set the text colour
	livesMsg.setPosition(50, 410);  // its position on the screen

	scoreMsg.setFont(font);  // set the font for the text    
	scoreMsg.setCharacterSize(24); // set the text size
	scoreMsg.setFillColor(sf::Color::White); // set the text colour
	scoreMsg.setPosition(50, 450);  // its position on the screen

	currencyMsg.setFont(font);  // set the font for the text    
	currencyMsg.setCharacterSize(24); // set the text size
	currencyMsg.setFillColor(sf::Color::White); // set the text colour
	currencyMsg.setPosition(50, 490);  // its position on the screen
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

void Game::playMusic()
{
	if (gameModes::game == currentState)
	{
		if (gamePlayTunes.openFromFile("ASSETS//MUSIC//gamePlay.wav"))
		{
			gamePlayTunes.play();
		}
	}

	else
	{
		if (menuTunes.openFromFile("ASSETS//MUSIC//menuMusic.wav"))
		{
			menuTunes.play();
		}
	}

	
}
void Game::asteroidCollision()
{


	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		//loop for the bullets array
		for (int j = 0; j < MAX_BULLETS; j++)
		{
			//checks for the collision of the alien array and the bullet array 
			if (bulletArray[j].getBody().getGlobalBounds().intersects(asteroidArray[i].getBody().getGlobalBounds()))
			{
				//sets the new pos of the aliens
				asteroidArray[i].setAlive(false);
				asteroidArray[i].setPosition(sf::Vector2f(-900, -100));
				asteroidArray[i].setSpeed(0);
				drawCollectible();

			}
		}
	}


	// Check if player collides with asteroid 
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		if (playerOne.getBody().getGlobalBounds().intersects(asteroidArray[i].getBody().getGlobalBounds()))
		{
			//sets the position and the subs 1 for player live and adds to score
			playerOne.setPosition(50, 50);
			playerLives = playerLives - 1;
			score = score - 1;
		}
		if (playerLives == 0)
		{
			//sets player to dead and its position if the players lives is 0
			playerOne.setAlive(false);
			playerOne.setPosition(-50, -50);
		}
	}

	if (playerOne.getBody().getGlobalBounds().intersects(theCollectables.getBody().getGlobalBounds()))
	{
		//sets the position and the subs 1 for player live and adds to score
		
		Game::currentState = gameModes::gameOverGood;
		
	}
	
   
}


void Game::drawCollectible()
{
	// We want the collectible to draw when an asteroid is dead 
	gems.render(m_window);
}

void Game::enemyCollision()
{

	// Check is player collides with alien
	for (int i = 0; i < MAX_ALIENS; i++)
	{
		if (playerOne.getBody().getGlobalBounds().intersects(alienArray[i].getBody().getGlobalBounds()))
		{

			playerOne.setPosition(50, 50);//temporary
			playerLives = playerLives - 1;
			score = score - 1;
		}
		if (playerLives == 0)
		{
			playerOne.setAlive(false);
			playerOne.setPosition(-50, -50);
		}
	}


	// remember to ask why is this there twice?


	//loop for alien array
	for (int i = 0; i < MAX_ALIENS; i++)
	{
		//loop for the bullets array
		for (int j = 0; j < MAX_BULLETS; j++)
		{
			//checks for the collision of the alien array and the bullet array 
			if (bulletArray[j].getBody().getGlobalBounds().intersects(alienArray[i].getBody().getGlobalBounds()))
			{
				//sets the new pos of the aliens
				alienArray[i].setPosition(-700, 700);
				//sets the death sprite
				enemyAlien.deathSprite();
				//adds the enemy kill sprite
				score = score + enemyKillScore;
				/*playerCurrency.alienShot();*/
				monies = playerCurrency.getCurrency();
				monies = monies + 200;
				playerCurrency.setCurrency(monies);
			}
		}
	}
	//loop for alien array 



} // last curly boii in this class



/// <summary>
/// Update the game world
/// loads collisions , movements and directions
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	
	
	// Splash Screen update
	if (gameModes::splashMode == currentState)
	{
		splash.update();
	}
	if (gameModes::shop == currentState)
	{
		currentBulletSpeed = playerBullet.getSpeed();
		currentSpeed = playerOne.getSpeed();
		money = playerCurrency.getCurrency();
		shopMenu.update(currentSpeed, money , currentBulletSpeed);

		newSpeed = shopMenu.getSpeed();
		playerOne.setSpeed(newSpeed);

		newBulletSpeed = shopMenu.getBulletSpeed();
		playerBullet.setSpeed(newBulletSpeed);
		
	}
	newCurrency = shopMenu.getCurrency();
	playerCurrency.setCurrency(newCurrency);
	if (gameModes::gameOver == currentState)
	{
		deathGameOver.update();
	}


	// Menu mode
	if (gameModes::mainMenu == currentState)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			Game::currentState = gameModes::help;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			Game::currentState = gameModes::game;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Game::currentState = gameModes::shop;
		}
	}

	// Help mode 
	if (gameModes::help == currentState)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			Game::currentState = gameModes::mainMenu;
		}
	}

	// Gameplay mode
	else if (gameModes::game == currentState)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			Game::currentState = gameModes::mainMenu;
		}
		for (int index = 0; index < MAX_ASTEROIDS; index++)
		{
			asteroidArray[index].update();
		}

		for (int i = 0; i < MAX_ALIENS; i++)

		{
			alienArray[i].arrayMovement();
			alienArray[i].arrayDirection();

			if (alienArray[i].getAlive() == false)
			{
				theCollectables.render(m_window);
			}
		}


		//function calls for the bullet, movement, asteroid and enemy collision
		playerBullet.load();
		playerOne.movement();
		asteroidCollision();
		enemyCollision();


		// Shoot bullets 
		if (timer < maxCount)
		{
			timer++;
		}


		//key press for the bullets shooting
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//if to check if timer less than max count
			if (timer >= maxCount)
			{
				//bool to check if found is false
				bool found = false;
				for (int i = 0; i < MAX_BULLETS && !found; i++)
				{
					if (!bulletArray[i].getAlive())
					{
						playerOne.playerShooting(bulletArray[i]);
						timer = 0;
						found = true;
					}
				}
			}
			
		}
	

		for (int i = 0; i < MAX_BULLETS; i++)
		{
			bulletArray[i].movement();
		}
		for (int i = 0; i < MAX_ALIENS; i++)
		{
			if (playerOne.getAlive() == false)
			{
				Game::currentState = gameModes::gameOver;
			}
	    }
	}
	// Exit Game
	else if (m_exitGame)
	{
		m_window.close();
	}

	
}



/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear();
	if (gameModes::gameOverGood == currentState)
	{
		winGameOer.render(m_window, score);
	}

	// Game over 
	if (gameModes::gameOver == currentState)
	{
		deathGameOver.render(m_window , score);
	}

	// Shop
	if (gameModes::shop == currentState)
	{
		shopMenu.render(m_window, playerCurrency.getCurrency());
	}
	// Splashscreen mode 
	
	if (gameModes::splashMode == currentState)
	{
		splash.render(m_window);
	}

	// Main Menu
	if (gameModes::mainMenu == currentState)
	{
		menuObject.create(m_window);
	}

	// Help
	if (gameModes::help == currentState)
	{
		helpScreen.render(m_window);
	}

	// Gameplay mode
	if (gameModes::game == currentState)
	{
		m_window.draw(m_welcomeMessage);
		m_window.draw(m_logoSprite);
		m_window.draw(backgroundSprite);
		// Draw the player while they are alive 
		if (playerOne.getAlive() == true)
		{
			m_window.draw(playerOne.getBody());
		}
		// Draw the bullets 
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (bulletArray[i].getAlive() == true)
			{
				m_window.draw(bulletArray[i].getBody());
			}
		}
		// Draw the asteroids if they are alive 
		for (int index = 0; index < MAX_ASTEROIDS; index++)
		{
			if (asteroidArray[index].getAlive())
			{
				asteroidArray[index].render(m_window);
			}
		}

		// Draw the aliens 
		for (int index = 0; index < MAX_ALIENS; index++)
		{

			alienArray[index].render(m_window);

		}
		for (int index = 0; index < MAX_ASTEROIDS; index++)
		{
			if (asteroidArray[index].getAlive() == false)
			{
				theCollectables.render(m_window);
			}
		}

		// Setting up lives and scores
		livesMsg.setString(" Lives : " + std::to_string(playerLives));
		scoreMsg.setString(" Score : " + std::to_string(score));
		currencyMsg.setString("Currency :" + std::to_string(playerCurrency.getCurrency()));
		m_window.draw(scoreMsg);
		m_window.draw(livesMsg);
		m_window.draw(currencyMsg);
	}

	m_window.display();


}



