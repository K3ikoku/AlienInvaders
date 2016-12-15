#pragma once
#include <SFML\Graphics.hpp>
#include "Bullet.h"


class Entity
{
public:
	Entity();
	~Entity();

	virtual void Update(sf::RenderWindow& window, float timeElapsed) = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;
	
	const std::vector<Bullet*> GetBullets() const { return m_bullets; };

	virtual void Die() = 0;

protected:
	int width;
	int height;
	float speed;
	float xPos;
	float yPos;

	std::vector<Bullet*> m_bullets;
	static sf::Clock gameClock;

};

