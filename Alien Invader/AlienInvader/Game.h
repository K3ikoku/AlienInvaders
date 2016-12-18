#pragma once

#include <stack>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "DrawableManager.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>



class Game
{
public:

	Game();

	sf::RenderWindow m_window;

	void GameLoop();


private:
	std::vector<Entity*> m_entities;

	DrawableManager* m_drawManager;

	sf::Texture m_backgroundTex;
	sf::Texture m_livesTex;
	sf::Texture m_numeralTex;

	sf::Sprite m_backgroundSpr;
	sf::Sprite m_livesSpr;
	sf::Sprite m_numeralXSpr;

	float m_timeElapsed;
	int m_nrOfLives;
	int m_score;
	bool m_gameOver;
	bool m_newGame;

	sf::Time m_lastSpawn;
	sf::Time m_spawnCD;
	sf::Clock m_spawnClock;

	sf::Font* m_font;
	sf::Text m_guiScoreText;
	sf::Text m_guiScorePoints;
	sf::Text m_guiLives;
	sf::Text m_guiGameOver;

	void StartGame();

	void Spawner();
	void Update();
	void Collision();
	void Draw();
	void Gui();
};

