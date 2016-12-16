#pragma once

#include <stack>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "SpriteManager.h"
#include "GUIManager.h"
#include <vector>



class Game
{
public:

	Game();
	~Game();

	sf::RenderWindow m_window;


	void gameLoop();


private:
	SpriteManager* m_spriteManager;
	GUIManager* m_guiManager;
	Player* m_player;

	sf::Sprite m_background;
	sf::Sprite m_livesSpr;
	sf::Sprite m_numeralX;

	float m_timeElapsed;
	int m_nrOfLives;
	int m_score;
	bool m_gameOver;

	sf::Time m_lastSpawn;
	sf::Time m_spawnCD;
	sf::Clock m_spawnClock;

	sf::Font* m_font;
	sf::Text m_guiScoreText;
	sf::Text m_guiScorePoints;
	sf::Text m_guiLives;
	sf::Text m_guiGameOver;

	std::vector<Entity*> m_entities;
	std::vector<sf::Drawable> m_guiElements;
	void StartGame();

	void Spawner();
	void Update();
	void Collision();
	void Draw();
	void Gui();
};

