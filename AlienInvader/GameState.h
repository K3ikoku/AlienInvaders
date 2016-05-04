#pragma once
#include <SFML/Window.hpp>
#include <SFML\Graphics.hpp>
#include "Game.h"
#include <iostream>


class GameState
{
public:
	Game* m_game;

	virtual void draw(const float m_dt) = 0;
	virtual void update(const float m_dt) = 0;
	virtual void handleInput() = 0;

	GameState();
	~GameState();



};

