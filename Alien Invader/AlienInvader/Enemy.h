#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "Player.h"

class Enemy : public Entity
{
public:
	enum LEFT_OR_RIGHT
	{
		LEFT,
		RIGHT,
		LAST
	};

	Enemy(sf::RenderWindow& window, SpriteManager& spriteManager);
	~Enemy();

	void Update(sf::RenderWindow& window, float timeElapsed) override;

	void Draw(sf::RenderWindow& window) override;

	void Collision(Entity* player) override;

	void Die();

	const std::vector<Entity*> &GetBullets() const { return m_bullets; };

	bool IsDead() const { return m_isDead; };

	sf::Sprite GetSprite() const { return m_sprite; };


private:

	void Fire();

	std::string m_bulletType;
	bool m_isDead;
	LEFT_OR_RIGHT m_dir;
	LEFT_OR_RIGHT m_pos;
	std::vector<Entity*> m_bullets;

	sf::Sprite m_sprite;
	sf::Time m_lastFired;
	sf::Time m_cd;

	SpriteManager& m_spriteManager;
};

