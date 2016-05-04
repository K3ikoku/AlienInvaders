#include "GameStateEditor.h"



void GameStateEditor::draw(const float m_dt)
{
	this->m_game->m_window.clear(sf::Color::Black);
	this->m_game->m_window.draw(this->m_game->m_background);

	return;
}

void GameStateEditor::update(const float m_dt)
{
	return;
}

void GameStateEditor::handleInput()
{
	sf::Event m_event;

	while (this->m_game->m_window.pollEvent(m_event))
	{
		if (m_event.Closed)
		{
			this->m_game->m_window.close();
			break;
		}
	}
}

GameStateEditor::GameStateEditor(Game* m_game)
{
	this->m_game = m_game;
	
}


GameStateEditor::~GameStateEditor()
{
}
