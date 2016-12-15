#pragma once
#include <string>
#include "SFML\Graphics.hpp"
#include "TextureManager.h"

class TextureManager;
class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	sf::Sprite createSprite(const std::string& name, const float posX, const float posY, 
				const int sizeX, const int sizeY, const bool repeat);

private:
	TextureManager* m_texManager;
};

