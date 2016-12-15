#include "Player.h"



Player::Player(SpriteManager& spriteManager):
	m_lives(10),
	m_score(0),
	m_lastFired(),
	m_cd(sf::seconds(0.5f)),
	m_spriteManager(spriteManager)
{
	width = 112;
	height = 75;
	speed = 700.0f;

	m_sprite.setOrigin(width / 2.0f, height / 2.0f);
	m_sprite = m_spriteManager.createSprite("player", 320, 920, width, height, false);
}


Player::~Player()
{
}

void Player::Update(sf::RenderWindow & window, float timeElapsed)
{

	xPos = m_sprite.getPosition().x;
	yPos = m_sprite.getPosition().y;

	HandleInput(window, timeElapsed);

	//Update the bullets
	for (unsigned int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets[i]->Update(window, timeElapsed);
	}
}

void Player::Draw(sf::RenderWindow & window)
{
	//Draw player sprite
	window.draw(m_sprite);

	//Draw bullets
	for (unsigned int i = 0; i < m_bullets.size(); i++)
	{
		if (m_bullets[i]->IsDead())
		{
			delete m_bullets[i];
			m_bullets.erase(m_bullets.begin + i);
			i--;
		}
		else
		{
			m_bullets[i]->Draw(window);
		}
	}
}

void Player::Collision(Entity* entity)
{
	for (unsigned int i = 0; i < entity->GetBullets().size; i++)
	{
		if (m_sprite.getGlobalBounds().intersects(entity->GetBullets[i]->GetSprite().getGlobalBounds()))
		{
			entity->GetBullets[i]->Die();

			Die();
		}
	}
}

void Player::SetLives(int lives)
{
	m_lives = lives;
}

void Player::SetScore(int score)
{
	m_score = score;
}

void Player::SetPos(float x, float y)
{
	m_sprite.setPosition(x, y);
}

void Player::Die()
{
	m_lives -= 1;
}

void Player::HandleInput(sf::RenderWindow & window, float elapsedTime)
{
	//Check if the player is pressing left button
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//Check if the player is within the window
		if (xPos <= width / 2.0f)
		{
			xPos = width / 2.0f;
		}
		else
		{
			//Move the player
			xPos -= speed * elapsedTime;
		}
	}

	//Check if the player is pressing right button
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		//Check if the player is within the window
		if (xPos >= window.getSize().x - (width / 2.0f))
		{
			xPos = window.getSize().x - (width / 2.0f);
		}
		else
		{
			//Move the player
			xPos += speed * elapsedTime;
		}
	}

	//Check if the player is pressing up button
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//Check if the player is within the window
		if (yPos <= height / 2.0f)
		{
			yPos = height / 2.0f;
		}
		else
		{
			//Move the player
			yPos -= speed * elapsedTime;
		}
	}

	//Check if the player is pressing down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//Check if the player is within the window
		if (yPos >= window.getSize().y - (width / 2.0f))
		{
			yPos = window.getSize().y - (width / 2.0f);
		}
		else
		{
			//Move the player
			yPos += speed * elapsedTime;
		}
	}

	//Check if the player is pressing space
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Fire();
	}

	for (unsigned int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets[i]->Update(window, elapsedTime);
	}
}

void Player::Fire()
{
	if (m_lastFired + m_cd < gameClock.getElapsedTime())
	{
		sf::Vector2f* m_bulletPos = new sf::Vector2f(xPos, yPos);

		Bullet* bullet = new Bullet(m_bulletPos, m_spriteManager, Bullet::UP);
		m_bullets.push_back(bullet);

		m_lastFired = gameClock.getElapsedTime();
	}
}
