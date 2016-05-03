#include "Game.h"
#include <stack>


void Game::pushState(Application* m_state)
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

void Game::changeState(Application* m_state)
{
	if (!this->m_states.empty())
		popState();
	pushState(m_state);

	return;
}

Application* Game::peekState()
{
	if (this->m_game - m_states.empty()) 
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
	this->m_window.create(sf::VideoMode(640, 960, "Alien Invader"));
	this->m_window.setFramerateLimit(60);
}


Game::~Game()
{
}

