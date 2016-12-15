#include "Enemy.h"



Enemy::Enemy(sf::Vector2f pos, SpriteManager& spriteManager) :
	m_isDead(false),
	m_cd(sf::seconds(0.5f)),
	m_spriteManager(spriteManager)
{
	srand((unsigned int)time(NULL));

	width = 91;
	height = 91;
	speed = 400;
	//Get a random value of the enum DIR
	m_dir = static_cast<DIR>(rand() % LAST);

	m_sprite.setOrigin(width / 2.0f, height / 2.0f);
	m_sprite = m_spriteManager.createSprite("enemy", pos.x, pos.y, width, height, false);
}


Enemy::~Enemy()
{
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

	for (unsigned int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets[i]->Update(window, timeElapsed);
	}
}

void Enemy::Draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);

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

void Enemy::Die()
{
	m_isDead = true;
}

void Enemy::Collision(Entity * player)
{
}

void Enemy::Fire()
{
	if (m_lastFired + m_cd < gameClock.getElapsedTime())
	{
		sf::Vector2f* m_bulletPos = new sf::Vector2f(xPos, yPos);

		Bullet* bullet = new Bullet(m_bulletPos, m_spriteManager, Bullet::DOWN);
		m_bullets.push_back(bullet);

		m_lastFired = gameClock.getElapsedTime();
	}
}
