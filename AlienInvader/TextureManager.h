#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>


class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void loadTexture(const std::string& m_name, const std::string &m_fileName);

	sf::Texture& getRef(const std::string& m_texture);

private:
	//Array of textures used
	std::map< std::string, sf::Texture > textures;
};

