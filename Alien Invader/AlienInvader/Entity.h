#pragma once
#include <SFML\Graphics.hpp>
#include "SpriteManager.h"
//#include "Bullet.h"


class Entity
{
public:
	Entity();
	~Entity();

	
	virtual void Update(sf::RenderWindow& window, float timeElapsed) = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;
	
	virtual void Collision(Entity* enemy) = 0;

	virtual void Die() = 0;

	sf::Sprite GetSprite() const { return m_sprite; };

	const std::vector<Entity*> &GetBullets() const { return m_bullets; };

	bool IsDead() const { return m_isDead; };
	

protected:
	int width;
	int height;
	float speed;
	float xPos;
	float yPos;
	bool m_isDead;
	sf::Sprite m_sprite;
	//std::vector<Bullet*> m_bullets;
	static sf::Clock gameClock;
	std::vector<Entity*> m_bullets;

};

