#pragma once
#include <SFML\Graphics.hpp>
class Entity
{
public:
	Entity();
	~Entity();

	sf::Sprite m_sprite;

	float m_moveSpeed = 4;

	virtual void draw(sf::RenderWindow& window);

	virtual void update();

private:
	virtual void move();
	virtual void collisionCheck();

};

