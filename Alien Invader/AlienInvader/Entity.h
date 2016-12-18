#pragma once
#include <SFML\Graphics.hpp>
#include "DrawableManager.h"


class Entity
{
public:
	Entity();
	enum TYPE
	{
		PLAYER,
		ENEMY,
		BULLET
	};
	virtual const TYPE& GetType() = 0;
	virtual const TYPE& GetTargetType() = 0;

	virtual void Update(sf::RenderWindow& window, float timeElapsed) = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;
	
	virtual void Die() = 0;

	virtual void Collision(std::vector<Entity*> vector) = 0;

	virtual sf::Sprite GetSprite() = 0;

	virtual bool IsDead() = 0;
	

protected:
	int width;
	int height;
	float speed;
	float xPos;
	float yPos;
	static sf::Clock gameClock;

};

