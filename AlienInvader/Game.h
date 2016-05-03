#pragma once

#include <stack>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Application.h"


class Game : Application
{
public:

	std::stack<Application*> m_states;

	sf::RenderWindow m_window;

	void pushState(Application* m_states);
	void popState();
	void changeState(Application* m_states);
	Application* peekState();

	void gameLoop();
	Game();
	~Game();
};

