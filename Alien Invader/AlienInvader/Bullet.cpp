#include "Bullet.h"

Bullet::Bullet(sf::Vector2f * pos, DrawableManager& drawManager, DIRECTION dir, std::vector<Entity*>& entities) :
	m_isDead(false),
	m_dir(dir),
	m_type(TYPE::BULLET),
	m_entities(entities)
{
	
	width = 9;
	height = 54;
	speed = 900.0f;


	//Check if the bullet is the player or the enemies and set the sprite accordingly
	if (m_dir == UP)
	{
		m_bulletType = "bullet_player";
		m_targetType = TYPE::ENEMY;
	}
	else if(m_dir == DOWN)
	{
		m_bulletType = "bullet_enemy";
		m_sprite.setRotation(180);
		m_targetType = TYPE::PLAYER;
	}
	else
	{
		std::cout << "Wrong type of direction inserted\n";
	}

	//Get the texture and create the sprite for the bullet
	m_texture = drawManager.GetTextureRef(m_bulletType, false, true);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(width / 2.0f, height / 2.0f);
	m_sprite.setPosition(pos->x, pos->y);
	
}

Bullet::~Bullet()
{
}

const Entity::TYPE & Bullet::GetType()
{
	return m_type;
}

const Entity::TYPE & Bullet::GetTargetType()
{
	return m_targetType;
}

void Bullet::Update(sf::RenderWindow & window, float timeElapsed)
{
	xPos = m_sprite.getPosition().x;
	yPos = m_sprite.getPosition().y;


	//Check which direction the bullet is supposed to go and move it accordingly
	if (m_dir == UP)
	{
		yPos -= timeElapsed * speed;
	}
	else if (m_dir == DOWN)
	{
		yPos += timeElapsed * speed;

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

void Bullet::Collision(std::vector<Entity*> vector)
{
	//Loop the bullet through all the entities in the vector and destroy them if they are supposed to be able to collide
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		if (!vector[i]->IsDead() && vector[i]->GetTargetType() == m_type && vector[i]->GetType() != TYPE::BULLET)
		{
			if (m_sprite.getGlobalBounds().intersects(vector[i]->GetSprite().getGlobalBounds()))
			{
				vector[i]->Die();

				Die();
			}
		}
	}
}


void Bullet::Die()
{
	m_isDead = true;
}

bool Bullet::IsDead()
{
	return m_isDead;
}

sf::Sprite Bullet::GetSprite()
{
	return m_sprite;
}