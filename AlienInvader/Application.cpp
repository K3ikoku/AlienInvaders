#include "Application.h"
#include <iostream>

Application::Application()
{
}


Application::~Application()
{
}

void Application::awake()
{
	

	loadPictures();
}


void Application::loadPictures()
{
	sf::Texture m_backgroundTexture; //Create variable for the background image and load the image
	if (!m_backgroundTexture.loadFromFile("assets/sprites/background.png", sf::IntRect(0, 0, 640, 955)))
	{
		std::cout << "Error while loading background image" << std::endl;
	}

	sf::Sprite m_background;

	m_background.setTexture(m_backgroundTexture);


	sf::Texture m_bulletEnemyTexture; //Create variable for the enemy bullet image and load the image
	if (!m_bulletEnemyTexture.loadFromFile("assets/sprites/bullet_enemy.png"))
	{
		std::cout << "Error while loading enemy bullet image" << std::endl;
	}

	sf::Texture m_bulletPlayerTexture; //Create variable for player bullet image and load the image
	if (!m_bulletPlayerTexture.loadFromFile("assets/sprites/bullet_player.png"))
	{
		std::cout << "Error while loading player bullet image" << std::endl;
	}

	sf::Texture m_enemyTexture; //Create variable for enemy image and load the image
	if (!m_enemyTexture.loadFromFile("assets/sprites/enemy.png"))
	{
		std::cout << "Error while loading enemy image" << std::endl;
	}

	sf::Texture m_numeralXTexture; //Create variable for numeral x image and load the image
	if (!m_numeralXTexture.loadFromFile("assets/sprites/numeralX.png"))
	{
		std::cout << "Error while loading numeral X image" << std::endl;
	}

	sf::Texture m_playerTexture; //Create variable for player image and load the image
	if (!m_playerTexture.loadFromFile("assets/sprites/player.png"))
	{
		std::cout << "Error while loading player image" << std::endl;
	}

	sf::Texture m_playerLifeTexture; //Create variable for player life image and load the image
	if (!m_playerLifeTexture.loadFromFile("assets/sprites/player_life.png"))
	{
		std::cout << "Error while loading player life image" << std::endl;
	}

	sf::Texture m_starsTexture; //Create variable for stars image and load the image
	if (!m_starsTexture.loadFromFile("assets/sprites/stars.png"))
	{
		std::cout << "Error while loading stars image" << std::endl;
	}

}
