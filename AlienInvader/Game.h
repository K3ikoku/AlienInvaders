#pragma once

#include <stack>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "GameState.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"

class GameState;

class Game
{
public:

	std::stack<GameState*> m_states;

	sf::RenderWindow m_window;
	TextureManager m_texManager;
	sf::Sprite m_background;

	void pushState(GameState* m_states);
	void popState();
	void changeState(GameState* m_states);
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();

private: 
	void loadTextures();
	void loadPlayer();

	
};

