#pragma once
#include <SFML/Window.hpp>
#include <SFML\Graphics.hpp>
#include "Player.h"

class Application
{
public:
	Application();
	~Application();

	void start();

	void loadPictures();

	void gameLoop();

	

	//Variables
	sf::RenderWindow m_window;
	sf::Texture m_backgroundTexture;
	sf::Texture m_bulletEnemyTexture;
	sf::Texture m_bulletPlayerTexture;
	sf::Texture m_enemyTexture;
	sf::Texture m_numeralXTexture;
	sf::Texture m_playerTexture;
	sf::Texture m_playerLifeTexture;
	sf::Texture m_starsTexture;

	sf::Sprite m_background;
	sf::Sprite m_bulletEnemy;
	sf::Sprite m_bulletPlayer;
	sf::Sprite m_enemy;
	sf::Sprite m_numeralX;
	sf::Sprite m_player;
	sf::Sprite m_playerLife;
	sf::Sprite m_stars;
};

