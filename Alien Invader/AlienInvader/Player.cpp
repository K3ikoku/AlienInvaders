#include "Player.h"



Player::Player(DrawableManager& drawManager, std::vector<Entity*>& entities):
	m_lives(10),
	m_lastFired(),
	m_cd(sf::seconds(0.5f)),
	m_drawManager(drawManager),
	m_type(TYPE::PLAYER),
	m_targetType(TYPE::ENEMY),
	m_entities(entities)
{
	width = 112;
	height = 75;
	speed = 700.0f;

	m_texture = m_drawManager.GetTextureRef("player", false, true);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(width / 2.0f, height / 2.0f);
	m_sprite.setPosition(320, 920);
}


Player::~Player()
{
}

const Entity::TYPE& Player::GetType()
{
	return m_type;
}

const Entity::TYPE& Player::GetTargetType()
{
	return m_targetType;
}

void Player::Update(sf::RenderWindow & window, float timeElapsed)
{

	xPos = m_sprite.getPosition().x;
	yPos = m_sprite.getPosition().y;

	HandleInput(window, timeElapsed);
}

void Player::Draw(sf::RenderWindow & window)
{
	//Draw player sprite
	window.draw(m_sprite);
}

void Player::Collision(std::vector<Entity*> vector)
{
	//Loop through all entities in the vector and destroy them if they are supposed to collide
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		if (!vector[i]->IsDead() && vector[i]->GetTargetType() == m_type)
		{
			if (m_sprite.getGlobalBounds().intersects(vector[i]->GetSprite().getGlobalBounds()) && vector[i] != this)
			{

				vector[i]->Die();

				Die();
			}
		}
	}
}


void Player::Die()
{
	m_lives -= 1;
}

bool Player::IsDead()
{
	return m_isDead;
}

sf::Sprite Player::GetSprite()
{
	return m_sprite;
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
			xPos -= elapsedTime * speed;
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

	m_sprite.setPosition(xPos, yPos);
}

void Player::Fire()
{
	if (m_lives > 0)
	{
		if (m_lastFired + m_cd < gameClock.getElapsedTime())
		{
			//Take the current position of the player and create the bullet in that position
			sf::Vector2f* m_bulletPos = new sf::Vector2f(xPos, yPos);

			Bullet* bullet = new Bullet(m_bulletPos, m_drawManager, Bullet::UP, m_entities);
			m_entities.push_back(bullet);

			m_lastFired = gameClock.getElapsedTime();
		}
	}
}
