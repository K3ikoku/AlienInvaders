#include "Enemy.h"


Enemy::Enemy(sf::RenderWindow& window, DrawableManager& drawManager, std::vector<Entity*>& entities) :
	m_isDead(false),
	m_wasKilled(false),
	m_cd(sf::seconds(0.5f)),
	m_drawManager(drawManager),
	m_type(TYPE::ENEMY),
	m_targetType(TYPE::PLAYER),
	m_entities(entities)
{
	srand((unsigned int)time(NULL));

	width = 91;
	height = 91;
	speed = 400.0f;

	yPos = 0.0f;
	//Get a random value of the enum to select a random direction and spawn point
	m_dir = static_cast<DIRECTION>(rand() % LAST);
	m_pos = static_cast<DIRECTION>(rand() & LAST);

	if (m_pos == LEFT)
	{
		xPos = width;
	}
	else
	{
		xPos = window.getSize().x - width;
	}

	m_texture = m_drawManager.GetTextureRef("enemy", false, true);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(width / 2.0f, height / 2.0f);
	m_sprite.setPosition(xPos, yPos);
}


Enemy::~Enemy()
{
}

const Entity::TYPE & Enemy::GetType()
{
	return m_type;
}

const Entity::TYPE & Enemy::GetTargetType()
{
	return m_targetType;
}

void Enemy::Update(sf::RenderWindow & window, float timeElapsed)
{
	xPos = m_sprite.getPosition().x;
	yPos = m_sprite.getPosition().y;

	//Always move down
	yPos += speed * timeElapsed;

	//Check the DIR enum to see if moving left or right
	if (m_dir == LEFT)
	{
		xPos -= (speed / 2) * timeElapsed;
	}
	else if (m_dir == RIGHT)
	{
		xPos += (speed / 2) * timeElapsed;
	}

	//Check if the ship is moving outside of the window
	if (xPos < (width / 2))
	{
		m_dir = RIGHT;
	}
	else if(xPos > (window.getSize().x - (width / 2)))
	{
		m_dir = LEFT;
	}

	//If the ship is below the window destroy it
	if (yPos > window.getSize().y)
	{
		Die();
	}

	m_sprite.setPosition(xPos, yPos);

	Fire();
}

void Enemy::Draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Enemy::Die()
{
	m_isDead = true;
	//std::cout << this << "died\n";
}

void Enemy::Collision(std::vector<Entity*> vector)
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
				m_wasKilled = true;
			}
		}
	}
}

bool Enemy::IsDead()
{
	return m_isDead;
}

bool Enemy::WasKilled()
{
	return m_wasKilled;
}

sf::Sprite Enemy::GetSprite()
{
	 return m_sprite;
}

void Enemy::Fire()
{
	if (m_lastFired + m_cd < gameClock.getElapsedTime())
	{
		//Take the current position of the ship and create the bullet in its position
		sf::Vector2f* m_bulletPos = new sf::Vector2f(xPos, yPos);
		
		Bullet* bullet = new Bullet(m_bulletPos, m_drawManager, Bullet::DOWN, m_entities);
		m_entities.push_back(bullet);

		m_lastFired = gameClock.getElapsedTime();
	}
}
