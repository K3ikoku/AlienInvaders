#include "Game.h"
#include <stack>

void Game::gameLoop()
{
	sf::Clock m_clock;

	while (this->m_window.isOpen())
	{
		sf::Time m_elapsed = m_clock.restart();
		float m_dt = m_elapsed.asSeconds();
		
		this->m_window.clear(sf::Color::Black);
		//this->m_window.draw(*m_background);


		this->m_window.display();
	}
}
Game::Game()
{

	this->m_window.create(sf::VideoMode(640, 960), "Alien Invader");
	this->m_window.setFramerateLimit(60);

	//m_background = m_spriteManager->createSprite("background", 0, 0, 640, 960, true);
	m_background = m_spriteManager->createSprite("background", 0, 0, 640, 960, true);


}


