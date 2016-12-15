#include "Game.h"


Game::Game() :
	m_window(sf::VideoMode(640, 960), "Alien Invader"),
	m_font(nullptr), m_lastSpawn(),
	m_nrOfLives(0), m_score(0),
	m_gameOver(false),
	m_spawnCD(sf::seconds(1.5f)),
	m_spriteManager(new SpriteManager())
{

	m_window.setFramerateLimit(60);
	m_background = m_spriteManager->createSprite("background", 0, 0, 640, 960, true);

	m_lives.setOrigin(37.0f / 2.0f, 26.0f / 2.0f);
	m_lives = m_spriteManager->createSprite("player_life", 40, 35, 37, 26, false);
	
	m_numeralX.setOrigin(17 / 2, 17 / 2);
	m_numeralX = m_spriteManager->createSprite("numeralX", 70, 35, 17, 17, false);
}
Game::~Game()
{
}
void Game::gameLoop()
{
	sf::Clock clock;
	m_window.setFramerateLimit(60);


	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}

		// Check if player wants to reset
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && m_gameOver)
		{
			StartGame();
		}
		
		Gui();
		Spawner();
		Update();
		Collision();
		Draw();

		m_timeElapsed = clock.restart().asSeconds();
	}
}

void Game::StartGame()
{
	//Check if vector is empty 
	if (!m_entities.empty())
	{
		for (unsigned int i = 0; i < m_entities.size(); i++)
		{
			delete m_entities[i];
			m_entities.erase(m_entities.begin() + i);
			i--;
		}
	}
	//Create the player and put it in the first position of the entities vector
	Player* player = new Player(*m_spriteManager);
	m_entities[0] = player;
}

void Game::Spawner()
{
	//If it was more than 1.5 seconds since the last spawn spawn another enemy
	if (m_lastSpawn + m_spawnCD < m_spawnClock.getElapsedTime())
	{
		Enemy* enemy = new Enemy(m_window, *m_spriteManager);
		m_entities.push_back(enemy);
		m_lastSpawn = m_spawnClock.getElapsedTime();
	}
}

void Game::Update()
{
	//Update all entites
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->Update(m_window, m_timeElapsed);
	}

}

void Game::Collision()
{
	//Run the collision function for the player against all enemies and all enemies against the player
	for (unsigned int i = 1; i < m_entities.size(); i++)
	{
		m_entities[0]->Collision(m_entities[i]);

		m_entities[i]->Collision(m_entities[0]);
	}
}

void Game::Draw()
{
	m_window.clear(sf::Color::Black);
	m_window.draw(m_background);


	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		if (m_entities[i]->IsDead())
		{
			delete m_entities[i];
			m_entities.erase(m_entities.begin() + i);
			m_score += 10;
			i--;
		}
		else
		{
			m_entities[i]->Draw(m_window);
		}

	}
	m_window.display();
}


void Game::Gui()
{

}



