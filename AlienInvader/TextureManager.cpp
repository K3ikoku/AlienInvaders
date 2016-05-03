#include "TextureManager.h"



TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

const sf::Texture & TextureManager::getImage(const std::string & m_fileName)
{
	for (std::map<std::string, sf::Texture>::const_iterator m_it = textures.begin();
		m_it != textures.end();++m_it)
	{
		if (m_fileName == m_it->first)
		{
			std::cout << "Using existing image." << std::endl;
			return m_it->second;
		}

		sf::Texture m_texture;
		if (m_texture.loadFromFile("assets/sprites/" + m_fileName))
		{
			textures[m_fileName] = m_texture;
			std::cout << "loading image" << std::endl;
			return textures[m_fileName];
		}
		std::cout << "Error: image was not found" << std::endl;
	}
}
