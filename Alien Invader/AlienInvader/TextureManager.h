#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>


class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void loadTexture(const std::string& name);

	sf::Texture& getRef(const std::string& texture, const bool repeat);

private:
	//Array of textures used
	std::map< std::string, sf::Texture > textures;

};

