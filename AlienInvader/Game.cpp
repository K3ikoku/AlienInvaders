#include "Game.h"
#include <stack>


void Game::pushState(GameState* m_state)
{
	this->m_states.push(m_state);

	return;
}

void Game::popState()
{
	delete this->m_states.top();
	this->m_states.pop();

	return;
}

void Game::changeState(GameState* m_state)
{
	if (!this->m_states.empty())
		popState();
	pushState(m_state);

	return;
}

GameState* Game::peekState()
{
	if (this->m_states.empty()) 
		return nullptr;

	return this->m_states.top();
}


void Game::gameLoop()
{
	sf::Clock m_clock;

	while (this->m_window.isOpen())
	{
		sf::Time m_elapsed = m_clock.restart();
		float m_dt = m_elapsed.asSeconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update(m_dt);
		this->m_window.clear(sf::Color::Black);
		peekState()->draw(m_dt);
		this->m_window.display();
	}
}
Game::Game()
{
	this->loadTextures();
	this->loadPlayer();

	this->m_window.create(sf::VideoMode(640, 960), "Alien Invader");
	this->m_window.setFramerateLimit(60);

	this->m_background.setTexture(this->m_texManager.getRef, ("background"));
}


Game::~Game()
{
	while (!this->m_states.empty()) popState();
}

void Game::loadTextures()
{
	m_texManager.loadTexture("background", "assets/sprites/background.png");
	m_texManager.loadTexture("bulletEnemy", "assets/sprites/bullet_enemy.png");
	m_texManager.loadTexture("bulletPlayer", "assets/sprites/bullet_player.png");
	m_texManager.loadTexture("enemy", "assets/sprites/enemy.png");
	m_texManager.loadTexture("numeralX", "assets/sprites/numeralX.png");
	m_texManager.loadTexture("player", "assets/sprites/player.png");
	m_texManager.loadTexture("playerLife", "assets/sprites/player_life.png");
	m_texManager.loadTexture("stars", "assets/sprites/stars.png");
}

void Game::loadPlayer()
{

}

