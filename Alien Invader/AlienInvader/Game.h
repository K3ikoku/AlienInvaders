#pragma once

#include <stack>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "SpriteManager.h"
#include <vector>



class Game
{
public:

	sf::RenderWindow m_window;
	TextureManager m_texManager;


	void gameLoop();

	Game();
	~Game();

private:
	SpriteManager* m_spriteManager;
	sf::Sprite* m_background;
	std::vector<Entity> m_entities;

	
};

