#include "TextureManager.h"
#include <iostream>



TextureManager::TextureManager()
{
	loadTexture("background");
	loadTexture("bullet_enemy");
	loadTexture("bullet_player");
	loadTexture("enemy");
	loadTexture("numeralX");
	loadTexture("player");
	loadTexture("player_life");
	loadTexture("stars");

	std::cout << "Loaded all textures" << std::endl;

}


TextureManager::~TextureManager()
{
}

void TextureManager::loadTexture(const std::string& name)
{
	//Load the texture
	sf::Texture m_tex;
	m_tex.loadFromFile("assets/sprites/"  + name + ".png");

	//Add it to the list of textures
	this->textures[name] = m_tex;

	return;
}

sf::Texture& TextureManager::getRef(const std::string& texture, const bool repeat)
{
	//Function to give a reference to a texture for 
	sf::Texture& m_tex = this->textures.at(texture);
	m_tex.setRepeated(repeat);
	
		return m_tex;
	
}




