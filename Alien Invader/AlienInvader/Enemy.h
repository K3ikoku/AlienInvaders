#pragma once
#include "SpriteManager.h"
#include "Entity.h"
class Enemy : Entity
{
public:
	enum DIR
	{
		LEFT,
		RIGHT,
		LAST
	};
	Enemy(sf::Vector2f pos, SpriteManager& spriteManager);
	~Enemy();

	void Update(sf::RenderWindow& window, float timeElapsed) override;

	void Draw(sf::RenderWindow& window) override;

	void Die();

	void Collision(Entity* player);

	bool IsDead() const { return m_isDead; };

	sf::Sprite GetSprite() const { return m_sprite; };

private:

	void Fire();
	std::string m_bulletType;
	bool m_isDead;
	DIR m_dir;
	std::vector<Bullet*> m_bullets;

	sf::Sprite m_sprite;
	sf::Time m_lastFired;
	sf::Time m_cd;

	SpriteManager& m_spriteManager;
};

