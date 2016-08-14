#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::draw(sf::RenderWindow & window)
{
	window.draw(this->m_sprite);
}

void Entity::update()
{
	move();
	collisionCheck();

}

void Entity::collisionCheck()
{
}

void Entity::move()
{

}