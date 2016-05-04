#include "TextureManager.h"



TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

void TextureManager::loadTexture(const std::string & m_name, const std::string & m_fileName)
{
	//Load the texture
	sf::Texture m_tex;
	m_tex.loadFromFile(m_fileName);

	//Add it to the list of textures
	this->textures[m_name] = m_tex;

	return;
}

sf::Texture& TextureManager::getRef(const std::string& m_texture)
{
	return this->textures.at(m_texture);
}


