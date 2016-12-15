#pragma once
#include "Entity.h"
#include "bullet.h"


class Player : public Entity
{
public:
	Player(SpriteManager& spriteManager);
	~Player();

	void Update(sf::RenderWindow& window, float timeElapsed) override;

	void Draw(sf::RenderWindow& window) override;

	void Collision(Entity* enemy) override;
	void SetLives(int lives);
	void SetPos(float x, float y);
	void Die();

	bool IsDead() const { return false; };

	int GetLives() const { return m_lives; };

	sf::Sprite GetSprite() const { return m_sprite; };

	const std::vector<Entity*> GetBullets() const { return m_bullets; };
private:

	void HandleInput(sf::RenderWindow& window, float timeElapsed);
	void Fire();

	int m_lives;

	std::vector<Entity*> m_bullets;

	sf::Sprite m_sprite;
	sf::Time m_lastFired;
	sf::Time m_cd;

	SpriteManager& m_spriteManager;
	

};
