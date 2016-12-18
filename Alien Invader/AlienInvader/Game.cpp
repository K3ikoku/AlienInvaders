#include "Game.h"


Game::Game() :
	m_window(sf::VideoMode(640, 960), "Alien Invader"),
	m_font(nullptr), m_lastSpawn(),
	m_nrOfLives(0), m_score(0),
	m_gameOver(false),
	m_spawnCD(sf::seconds(1.5f)),
	m_drawManager(new DrawableManager()),
	m_newGame(true)

{
	//Get the background texture from the texture manager and create the sprite
	m_backgroundTex = m_drawManager->GetTextureRef("background", true, false);
	m_backgroundSpr.setTexture(m_backgroundTex);
	m_backgroundSpr.setTextureRect(sf::IntRect(0, 0, 640, 960));

	//Select font
	m_drawManager->SetFont("kenvector_future");

	//Create all the text elements for later
	m_guiLives = m_drawManager->CreateNumber(25, sf::Color::White, 80.0f, 20.0f);

	m_guiScorePoints = m_drawManager->CreateNumber(25,sf::Color::White, 460.0f, 15.0f);

	m_guiGameOver = m_drawManager->CreateText("Game Over", sf::Color::White,  40, 180.0f, (m_window.getSize().y / 2.0f));
	
	m_guiScoreText = m_drawManager->CreateText("Score",sf::Color::White, 25, 350.0f, 15.0f);

	//Get the texture for player and the numeral and create the sprites
	m_livesTex = m_drawManager->GetTextureRef("player_life", false, false);
	m_livesSpr.setTexture(m_livesTex);
	m_livesSpr.setOrigin(m_livesTex.getSize().x / 2.0f, m_livesTex.getSize().y / 2.0f);
	m_livesSpr.setPosition(40.0f, 35.0f);

	m_numeralTex = m_drawManager->GetTextureRef("numeralX", false, false);
	m_numeralXSpr.setTexture(m_numeralTex);
	m_numeralXSpr.setOrigin(m_numeralTex.getSize().x / 2.0f, m_numeralTex.getSize().y / 2.0f);
	m_numeralXSpr.setPosition(70.0f, 35.0f);
}

void Game::GameLoop()
{
	//Create the game clock and set the framerate of the window to 60 fps
	sf::Clock clock;
	m_window.setFramerateLimit(60);


	while (m_window.isOpen())
	{
		//Create an event for closing the window
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}

		// Check if player wants to reset if the game is over
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && m_gameOver)
		{
			m_newGame = true;
		}
		if (m_newGame)
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
	Player* player = new Player(*m_drawManager, m_entities);
	m_entities.push_back(player);
	m_gameOver = false;
	m_newGame = false;
}

void Game::Spawner()
{
	if (!m_gameOver)
	{
		//If it was more than 1.5 seconds since the last spawn spawn another enemy
		if (m_lastSpawn + m_spawnCD < m_spawnClock.getElapsedTime())
		{
			Enemy* enemy = new Enemy(m_window, *m_drawManager, m_entities);
			m_entities.push_back(enemy);
			m_lastSpawn = m_spawnClock.getElapsedTime();
		}
	}
}

void Game::Update()
{
	//Loop through all entities and make them move in the game
	if (m_entities.size() > 0)
	{
		for (unsigned int i = 0; i < m_entities.size(); i++)
		{
			if (m_entities[i] != nullptr)
			{
				m_entities[i]->Update(m_window, m_timeElapsed);
			}
		}
	}

}

void Game::Collision()
{

	//Run the collision function for the player against all enemies and all enemies against the player
	if (m_entities.size() > 0)
	{
		for (unsigned int i = 0; i < m_entities.size(); i++)
		{
			m_entities[i]->Collision(m_entities);
		}
	}
}

void Game::Draw()
{
	//Remove all sprites from the window and then draw the background over it
	m_window.clear(sf::Color::Black);
	m_window.draw(m_backgroundSpr);

	//If the game is over draw the game over text and if it isnt draw the player
	if (m_gameOver)
	{
		m_window.draw(m_guiGameOver);
	}
	else
	{
		m_entities[0]->Draw(m_window);
	}
	if (m_entities.size() > 0)
	{
		//Loop through all entities and draw them
		for (unsigned int i = 1; i < m_entities.size(); i++)
		{
			//Check if the entity is dead and if it is destroy it
			if (m_entities[i]->IsDead() == true)
			{
				//If the destroted element was an enemy ship add points to the scoreboard
				if (m_entities[i]->GetType() == Entity::TYPE::ENEMY)
				{
					bool wasKilled = dynamic_cast<Enemy*>(m_entities[i])->WasKilled();
					if (wasKilled)
					{
						m_score += 10;
					}
				}
				delete m_entities[i];
				m_entities.erase(m_entities.begin() + i);
				i--;
			}
			else
			{
				m_entities[i]->Draw(m_window);
			}

		}
	}
	//Draw all gui elements
	m_window.draw(m_guiLives);
	m_window.draw(m_guiScorePoints);
	m_window.draw(m_guiScoreText);
	m_window.draw(m_livesSpr);
	m_window.draw(m_numeralXSpr);



	m_window.display();
}


void Game::Gui()
{
	//Update the gui
	if (m_entities[0] != nullptr && !m_gameOver)
	{
		m_nrOfLives = dynamic_cast<Player*>(m_entities[0])->GetLives();


		if (m_nrOfLives <= 0)
		{
			m_gameOver = true;
			m_nrOfLives = 0;
			delete m_entities[0];
			m_entities.erase(m_entities.begin());
		}
	}
	m_guiLives.setString(std::to_string(m_nrOfLives));
	m_guiScorePoints.setString(std::to_string(m_score));
}



