#pragma once
#include "Entity.h"
#include "SpriteManager.h"
#include <SFML\Graphics.hpp>
class Bullet :
	public Entity
{
public:

	enum DIRECTION
	{
		UP,
		DOWN
	};

	Bullet(sf::Vector2f* pos, SpriteManager& spriteManager, DIRECTION dir);
	~Bullet();

	void Update(sf::RenderWindow& window, float timeElapsed) override;

	void Draw(sf::RenderWindow& window) override;

	void Die();

	bool IsDead() const { return m_isDead; };

	sf::Sprite GetSprite() const { return m_sprite; };

private:
	sf::Sprite m_sprite;
	std::string m_bulletType;
	DIRECTION m_dir;
	bool m_isDead;


};

