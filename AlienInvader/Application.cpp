#include "Application.h"
#include <iostream>
#include <SFML/Window.hpp>


Application::Application()
{
}


Application::~Application()
{
}

void Application::start()
{
	loadPictures();
	gameLoop();
	Player* player = new Player();
	
}


void Application::loadPictures()
{
	sf::Texture m_backgroundTexture; //Create variable for the background image and load the image
	if (!m_backgroundTexture.loadFromFile("assets/sprites/background.png", sf::IntRect(0, 0, 640, 960)))
	{
		std::cout << "Error while loading background image" << std::endl;
	}
	sf::Sprite m_background;
	m_background.setTexture(m_backgroundTexture);

	if (!m_bulletEnemyTexture.loadFromFile("assets/sprites/bullet_enemy.png"))
	{
		std::cout << "Error while loading enemy bullet image" << std::endl;
	}
	sf::Sprite m_bulletEnemy;
	m_bulletEnemy.setTexture(m_bulletEnemyTexture);

	sf::Texture m_bulletPlayerTexture; //Create variable for player bullet image and load the image
	if (!m_bulletPlayerTexture.loadFromFile("assets/sprites/bullet_player.png"))
	{
		std::cout << "Error while loading player bullet image" << std::endl;
	}
	sf::Sprite m_bulletPlayer;
	m_bulletPlayer.setTexture(m_bulletPlayerTexture);

	sf::Texture m_enemyTexture; //Create variable for enemy image and load the image
	if (!m_enemyTexture.loadFromFile("assets/sprites/enemy.png"))
	{
		std::cout << "Error while loading enemy image" << std::endl;
	}
	sf::Sprite m_enemy;
	m_enemy.setTexture(m_enemyTexture);

	sf::Texture m_numeralXTexture; //Create variable for numeral x image and load the image
	if (!m_numeralXTexture.loadFromFile("assets/sprites/numeralX.png"))
	{
		std::cout << "Error while loading numeral X image" << std::endl;
	}
	sf::Sprite m_numeralX;
	m_numeralX.setTexture(m_numeralXTexture);

	sf::Texture m_playerTexture; //Create variable for player image and load the image
	if (!m_playerTexture.loadFromFile("assets/sprites/player.png"))
	{
		std::cout << "Error while loading player image" << std::endl;
	}
	sf::Sprite m_player;
	m_player.setTexture(m_bulletPlayerTexture);

	sf::Texture m_playerLifeTexture; //Create variable for player life image and load the image
	if (!m_playerLifeTexture.loadFromFile("assets/sprites/player_life.png"))
	{
		std::cout << "Error while loading player life image" << std::endl;
	}
	sf::Sprite m_playerLife;
	m_playerLife.setTexture(m_playerLifeTexture);

	sf::Texture m_starsTexture; //Create variable for stars image and load the image
	if (!m_starsTexture.loadFromFile("assets/sprites/stars.png"))
	{
		std::cout << "Error while loading stars image" << std::endl;
	}
	sf::Sprite m_stars;
	m_stars.setTexture(m_starsTexture);
}

void Application::gameLoop()
{
	sf::RenderWindow m_window(sf::VideoMode(640, 960), "My window");
	// run the program as long as the window is open
	while (m_window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event m_event;
		while (m_window.pollEvent(m_event))
		{
			

			// "close requested" event: we close the window
			if (m_event.type == sf::Event::Closed)
				m_window.close();
		}
	}	
}
	


