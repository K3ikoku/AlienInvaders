#pragma once
#include "Entity.h"
#include "bullet.h"


class Player : public Entity
{
public:
	Player(DrawableManager& drawManagers, std::vector<Entity*>& entities);
	~Player();

	const TYPE& GetType() override;
	const TYPE& GetTargetType() override;

	void Update(sf::RenderWindow& window, float timeElapsed) override;

	void Draw(sf::RenderWindow& window) override;

	void Collision(std::vector<Entity*> vector) override;

	void Die();

	bool IsDead() override;

	int GetLives() const { return m_lives; };

	sf::Sprite GetSprite() override;

private:
	std::vector<Entity*>& m_entities;

	TYPE m_type;
	TYPE m_targetType;
	void HandleInput(sf::RenderWindow& window, float elapsedTime);
	void Fire();

	int m_lives;
	bool m_isDead;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Time m_lastFired;
	sf::Time m_cd;

	DrawableManager& m_drawManager;
	

};
