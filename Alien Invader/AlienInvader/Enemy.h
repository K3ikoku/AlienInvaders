#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "Player.h"

class Enemy : public Entity
{
public:
	enum DIRECTION
	{
		LEFT,
		RIGHT,
		LAST
	};

	Enemy(sf::RenderWindow& window, DrawableManager& drawManager, std::vector<Entity*>& entities);
	~Enemy();

	const TYPE& GetType() override;

	const TYPE& GetTargetType() override;

	void Update(sf::RenderWindow& window, float timeElapsed) override;

	void Draw(sf::RenderWindow& window) override;

	void Collision(std::vector<Entity*> vector) override;

	void Die() override;

	bool IsDead() override;

	bool WasKilled();

	sf::Sprite GetSprite() override;


private:
	std::vector<Entity*>& m_entities;

	void Fire();

	TYPE m_type;
	TYPE m_targetType;

	bool m_isDead;
	bool m_wasKilled;

	DIRECTION m_dir;
	DIRECTION m_pos;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Time m_lastFired;
	sf::Time m_cd;

	DrawableManager& m_drawManager;
};

