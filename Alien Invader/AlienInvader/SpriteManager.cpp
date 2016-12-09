#include "SpriteManager.h"



SpriteManager::SpriteManager() :
	m_texManager(new TextureManager())
{
}

sf::Sprite SpriteManager::createSprite(const std::string& name, const int posX, const int posY, 
	const int sizeX, const int sizeY, const bool repeat)
{
	//Create a sprite 
	sf::Sprite m_sprite;
	//Get the reference to the sprite and pass on information if its supposed to be repeated or not
	sf::Texture& m_tex = m_texManager->getRef(name, repeat);
	//Set position and size of the sprite
	m_sprite.setTextureRect(sf::IntRect(posX, posY, sizeX, sizeY));
	
	//Return sprite
	return m_sprite;
}


SpriteManager::~SpriteManager()
{
}
