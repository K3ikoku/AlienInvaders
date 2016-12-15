#include "Game.h"


Game::Game() :
	m_window(sf::VideoMode(640, 960), "Alien Invader"),
	m_font(nullptr), m_spawnClock(),
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
	//Start a new game
}

void Game::Spawner()
{
	//Spawn enemies
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
}

void Game::Draw()
{
	m_window.clear(sf::Color::Black);
	m_window.draw(m_background);


	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		/*if (m_entities[i]->GetIsDead() == true)
		{
			delete m_entities[i];
			m_entities.erase(m_entities.begin + i);
			i--;
		}*/

		//TODO: Continue with the code for drawing stuff
	}
	m_window.display();
}


void Game::Gui()
{

}



