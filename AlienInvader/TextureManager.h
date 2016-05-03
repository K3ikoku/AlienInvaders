#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>


class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	const sf::Texture& getImage(const std::string& m_fileName);

private:
	std::map< std::string, sf::Texture > textures;
};

