#pragma once
#include <string>
#include "SFML\Graphics.hpp"
#include "TextureManager.h"
#include <vector>	

class TextureManager;
class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	sf::Sprite* createSprite(const std::string& name, const int posX, const int posY, 
				const int sizeX, const int sizeY, const bool repeat);

private:
	TextureManager* m_texManager;
};

