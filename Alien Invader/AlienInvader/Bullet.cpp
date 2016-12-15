#include "Bullet.h"

Bullet::Bullet(sf::Vector2f * pos, SpriteManager& spriteManager, DIRECTION dir):
	m_isDead(false), m_dir(dir)
{
	
	width = 9;
	height = 54;
	speed = 900;


	//Check if the bullet is the player or the enemies and set the sprite accordingly
	if (m_dir == UP)
	{
		m_bulletType = "bullet_player";
	}
	else if(m_dir == DOWN)
	{
		m_bulletType = "bullet_enemy";
	}
	else
	{
		std::cout << "Wrong type of direction inserted\n";
	}

	m_sprite.setOrigin(width / 2.0f, height / 2.0f);
	m_sprite = spriteManager.createSprite(m_bulletType, pos->x, pos->y, width, height, false);
	
}

Bullet::~Bullet()
{
}

void Bullet::Update(sf::RenderWindow & window, float timeElapsed)
{
	xPos = m_sprite.getPosition().x;
	yPos = m_sprite.getPosition().y;


	//Check which direction the bullet is supposed to go and move it accordingly
	if (m_dir == UP)
	{
		yPos -= speed * timeElapsed;
	}
	else if (m_dir == DOWN)
	{
		yPos += speed * timeElapsed;
	}
	else 
	{
		std::cout << "Wrong type of direction \n";
	}

	m_sprite.setPosition(xPos, yPos);

	//Check if the bullet is inside the window and destroy if not
	if (yPos < 0 || yPos > window.getSize().y)
	{
		Die();
	}
}

void Bullet::Draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Bullet::Die()
{
	m_isDead = true;
}
