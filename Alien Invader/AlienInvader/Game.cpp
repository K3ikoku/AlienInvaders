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

	m_font = new sf::Font();
	if (!m_font->loadFromFile("assets/fonts/kenvector_future.ttf"))
	{
		perror("Font could not be loaded\n");
	}

	m_guiManager = new GUIManager(m_font, sf::Color::White);

	m_guiLives = m_guiManager->CreateNumber(25, 80.0f, 20.0f);
	//m_guiElements.push_back(m_guiLives);

	m_guiScorePoints = m_guiManager->CreateNumber(25, 460.0f, 15.0f);
	//m_guiElements.push_back(m_guiScorePoints);

	m_guiGameOver = m_guiManager->CreateText("Game Over", 40, (m_window.getSize().x / 2.0f), (m_window.getSize().y / 2.0f));
	//m_guiElements.push_back(m_guiGameOver);

	m_guiScoreText = m_guiManager->CreateText("Score", 25, 350.0f, 15.0f);
	//m_guiElements.push_back(m_guiScoreText);

	m_livesSpr.setOrigin(37.0f / 2.0f, 26.0f / 2.0f);
	m_livesSpr = m_spriteManager->createSprite("player_life", 40, 35, 37, 26, false);
	//m_guiElements.push_back(m_livesSpr);

	m_numeralX.setOrigin(17 / 2, 17 / 2);
	m_numeralX = m_spriteManager->createSprite("numeralX", 70, 35, 17, 17, false);
	//m_guiElements.push_back(m_numeralX);
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
	//TODO: Do a check if really supposed to start the game
	//TOOD: Do a check for when to print out game over
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
	//Draw all the gui elements
	m_window.draw(m_guiLives);
	m_window.draw(m_guiScorePoints);
	m_window.draw(m_guiGameOver);
	m_window.draw(m_guiScoreText);
	m_window.draw(m_livesSpr);
	m_window.draw(m_numeralX);



	m_window.display();
}


void Game::Gui()
{
	m_player = dynamic_cast<Player*>(m_entities[0]);
	m_nrOfLives = m_player->GetLives();


	if (!(m_nrOfLives > 0))
	{
		m_gameOver = true;
		m_nrOfLives = 0;
		delete m_entities[0];
		m_entities.erase(m_entities.begin());
	}

	m_guiLives.setString(std::to_string(m_nrOfLives));
	m_guiScorePoints.setString(std::to_string(m_score));
}



