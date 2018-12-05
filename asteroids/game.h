/// <summary>
/// @author: Jonelle Lawler, David Whiteford
/// Submission Date: 27/04/2018 
/// 
/// 
/// ISSUES:
/// No hanger 
/// 1. Don't know how to use switch so game modes checked with ifs 
/// 
/// 2. Had to use boolean in main menu class to then use to switch game mode as I has circular dependencies going on (googled my error), assuming that isn't very efficient? 
/// game class required main menu header, main menu required game header 
/// </summary>
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Player.h" 
#include "Alien.h"
#include "Bullets.h"
#include "Collectibles.h"
#include "Currency.h" 
#include "SplashScreen.h"
#include "Globals.h"
#include  "MainMenu.h"
#include "GameOver.h"
#include "Shop.h"
#include "Help.h"
#include "gameOverGood.h"

// I got rid of the code that caused the circular referencing but this stops circular referecening so we can change that back to how it used to  be i.. think
class MainMenu;
class GameOver;
class SplashScreen;
class Shop;
class Help;
class levelTwo;

class Game
{
public:
	Game();
	~Game();

	void run();
	void loadContent();

	static const int MAX_ASTEROIDS{ 10 };
	static const int MAX_GEMS{ 10 };

	// Enemy and bullet Arrays
	Asteroids asteroidArray[MAX_ASTEROIDS]; 
	static const int MAX_BULLETS{ 5 };
	Bullet bulletArray[MAX_BULLETS];
	static const int MAX_ALIENS{ 3 };
	Alien alienArray[MAX_ALIENS];
	Collectibles gems;
	static gameModes currentState;
	const int maxCount{ 10 };
	sf::Sprite backgroundSprite;
	sf::Texture backgroundImage;

	// Music
	sf::Music menuTunes;
	sf::Music gamePlayTunes;

	// Splash Screen object (sprite)
	SplashScreen splash;

	// Shop
	Shop shopMenu;

	// Game over 
	gameOver deathGameOver;
	gameOverGood winGameOer;

	//  Menu Object (sprite)
	MainMenu menuObject;


	// Help
	Help helpScreen;

	sf::RenderWindow m_window;

private:

	void processEvents();
	void playMusic();
	void update(sf::Time t_deltaTime);
	void render();
	void asteroidCollision();
	void drawCollectible();
	void enemyCollision();

	Player playerOne;
	Asteroids asteroidsAi;
	Alien enemyAlien;
	Bullet playerBullet;
	Collectibles theCollectables;
	Currency playerCurrency;
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo // what?
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	//variables for the game
	int speed{};
	int timer{ 0 };
	int score = 0;
	int enemyKillScore = 1;
	int playerLives = 5;
	//speeds and money variables
	float newSpeed{ 0 };
	float currentSpeed{0};
	int money{ 0 };
	int newMoney{ 0 };
	int newCurrency{ 0 };
	int currentBulletSpeed{ 0 };
	int newBulletSpeed{ 0 };
	int monies{ 0 };
	sf::Text livesMsg;
	sf::Text scoreMsg;
	sf::Text currencyMsg;
	sf::Font font;


	Currency currency;

};

#endif // !GAME

