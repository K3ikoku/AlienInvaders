#pragma once
#include "Entity.h"
#include "SpriteManager.h"
#include "Bullet.h"

class Player : Entity
{
public:
	Player(SpriteManager& spriteManager);
	~Player();

	void Update(sf::RenderWindow& window, float timeElapsed) override;

	void Draw(sf::RenderWindow& window) override;

	//TODO: Implement collision function
	void Collision();
	void SetLives(int lives);
	void SetScore(int score);
	void SetPos(float x, float y);


	int GetLives() const { return m_lives; };
	int GetScore() const { return m_score; };

	sf::Sprite GetSprite() const { return m_playerSprite; };

	const std::vector<Bullet*> GetBullets() const { return m_bullets; };
private:

	void HandleInput(sf::RenderWindow& window, float timeElapsed);
	void Fire();

	int m_lives;

	int m_score;

	std::vector<Bullet*> m_bullets;

	sf::Sprite m_playerSprite;
	sf::Time m_lastFired;
	sf::Time m_cd;
	

};
