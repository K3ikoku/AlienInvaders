#pragma once
#include "GameState.h"
#include <SFML\Graphics.hpp>

class GameStateEditor : public GameState
{
public:
	
	virtual void draw(const float m_dt);
	virtual void update(const float m_dt);
	virtual void handleInput();

	GameStateEditor(Game* m_game);

	~GameStateEditor();
};

