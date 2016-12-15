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
	

protected:
	int width;
	int height;
	float speed;
	float xPos;
	float yPos;

	static sf::Clock gameClock;

};

