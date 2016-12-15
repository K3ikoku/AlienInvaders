#include "Player.h"



Player::Player(SpriteManager& spriteManager):
	m_lives(10),
	m_score(0),
	m_lastFired(),
	m_cd(sf::seconds(0.5f))
{
	width = 112;
	height = 75;
	speed = 700.0f;

	m_playerSprite = spriteManager.createSprite("player", 320, 920, width, height, false);
	m_playerSprite.setOrigin(width / 2, height / 2);
}


Player::~Player()
{
}

void Player::Update(sf::RenderWindow & window, float timeElapsed)
{

	xPos = m_playerSprite.getPosition().x;
	yPos = m_playerSprite.getPosition().y;

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
	window.draw(m_playerSprite);

	//Draw bullets
	for (unsigned int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets[i]->Draw(window);
	}
}

void Player::Collision()
{

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
	m_playerSprite.setPosition(x, y);
}

void Player::HandleInput(sf::RenderWindow & window, float elapsedTime)
{
	//Check if the player is pressing left button
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//Check if the player is within the window
		if (xPos <= width / 2)
		{
			xPos = width / 2;
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
		if (xPos >= window.getSize().x - (width / 2))
		{
			xPos = window.getSize().x - (width / 2);
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
		if (yPos <= height / 2)
		{
			yPos = height / 2;
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
		if (yPos >= window.getSize().y - (width / 2))
		{
			yPos = window.getSize().y - (width / 2);
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
}

void Player::Fire()
{
	if (m_lastFired < gameClock.getElapsedTime())
	{
		sf::Vector2f* m_bulletPos = new sf::Vector2f(xPos, yPos);

		Bullet* bullet = new Bullet();
		m_bullets.push_back(bullet);
	}
}
