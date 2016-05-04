#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::draw(sf::RenderWindow & m_window)
{
	m_window.draw(this->m_sprite);
}

void Entity::update()
{
	

}
