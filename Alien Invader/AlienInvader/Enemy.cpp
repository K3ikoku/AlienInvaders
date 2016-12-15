#include "Enemy.h"


Enemy::Enemy(sf::RenderWindow& window, SpriteManager& spriteManager) :
	m_isDead(false),
	m_cd(sf::seconds(0.5f)),
	m_spriteManager(spriteManager)
{
	srand((unsigned int)time(NULL));

	width = 91;
	height = 91;
	speed = 400.0f;

	yPos = 0.0f;
	//Get a random value of the enum DIR
	m_dir = static_cast<LEFT_OR_RIGHT>(rand() % LAST);
	m_pos = static_cast<LEFT_OR_RIGHT>(rand() & LAST);

	if (m_pos == LEFT)
	{
		xPos = width;
	}
	else
	{
		xPos = window.getSize().x - width;
	}

	m_sprite.setOrigin(width / 2.0f, height / 2.0f);
	m_sprite = m_spriteManager.createSprite("enemy", xPos, yPos, width, height, false);
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
			m_bullets.erase(m_bullets.begin() + i);
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
	//Check if the ship is colliding with any of the players bullets or any of the players bullets and destroy them both
	if (m_sprite.getGlobalBounds().intersects(player->GetSprite().getGlobalBounds()))
	{
		Die();
		player->Die();
	}
	for (unsigned int i = 0; i < player->GetBullets().size(); i++)
	{
		Entity* target = player->GetBullets()[i];
		if (m_sprite.getGlobalBounds().intersects(target->GetSprite().getGlobalBounds()))
		{
			Die();

			target->Die();
		}
	}
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
