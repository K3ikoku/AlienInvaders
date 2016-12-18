#pragma once
#include "Entity.h"

class Bullet :
	public Entity
{
public:

	enum DIRECTION
	{
		UP,
		DOWN
	};

	Bullet(sf::Vector2f* pos, DrawableManager& drawManager, DIRECTION dir, std::vector<Entity*>& entities);
	~Bullet();

	const TYPE& GetType() override;
	const TYPE& GetTargetType() override;

	void Update(sf::RenderWindow& window, float timeElapsed) override;

	void Draw(sf::RenderWindow& window) override;

	void Collision(std::vector<Entity*> vector) override;

	void Die() override;

	bool IsDead() override;

	sf::Sprite GetSprite() override;

private:
	std::vector<Entity*>& m_entities;
	TYPE m_type;
	TYPE m_targetType;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	std::string m_bulletType;
	DIRECTION m_dir;
	bool m_isDead;


};

