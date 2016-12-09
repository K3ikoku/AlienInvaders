#pragma once

#include <stack>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "SpriteManager.h"
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

	sf::Sprite m_background;
	sf::Sprite m_lives;
	sf::Sprite m_number;

	float m_timeElapsed;
	int m_nrOfLives;
	int m_score;
	bool m_gameOver;

	sf::Time m_spawnTimer;
	sf::Time m_spawnCD;
	sf::Clock m_spawnClock;

	sf::Font* m_font;

	std::vector<Entity*> m_entities;

	void StartGame();

	void Spawner();
	void Update();
	void Collision();
	void Draw();
	void Gui();




	
};

