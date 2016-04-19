#include "Application.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Application::Application()
{
}


Application::~Application()
{
}


void Application::loadPictures()
{
	sf::Texture m_background; //Create variable for the background image and load the image
	if (!m_background.loadFromFile("assets/sprites/background.png"))
	{
		std::cout << "Error while loading background image" << std::endl;
	}

	sf::Texture m_bulletEnemy; //Create variable for the enemy bullet image and load the image
	if (!m_bulletEnemy.loadFromFile("assets/sprites/bullet_enemy.png"))
	{
		std::cout << "Error while loading enemy bullet image" << std::endl;
	}

	sf::Texture m_bulletPlayer; //Create variable for player bullet image and load the image
	if (!m_bulletPlayer.loadFromFile("assets/sprites/bullet_player.png"))
	{
		std::cout << "Error while loading player bullet image" << std::endl;
	}

	sf::Texture m_enemy; //Create variable for enemy image and load the image
	if (!m_enemy.loadFromFile("assets/sprites/enemy.png"))
	{
		std::cout << "Error while loading enemy image" << std::endl;
	}

	sf::Texture m_numeralX; //Create variable for numeral x image and load the image
	if (!m_numeralX.loadFromFile("assets/sprites/numeralX.png"))
	{
		std::cout << "Error while loading numeral X image" << std::endl;
	}

	sf::Texture m_player; //Create variable for player image and load the image
	if (!m_player.loadFromFile("assets/sprites/player.png"))
	{
		std::cout << "Error while loading player image" << std::endl;
	}

	sf::Texture m_playerLife; //Create variable for player life image and load the image
	if (!m_playerLife.loadFromFile("assets/sprites/player_life.png"))
	{
		std::cout << "Error while loading player life image" << std::endl;
	}

	sf::Texture m_stars; //Create variable for stars image and load the image
	if (!m_stars.loadFromFile("assets/sprites/stars.png"))
	{
		std::cout << "Error while loading stars image" << std::endl;
	}

}
