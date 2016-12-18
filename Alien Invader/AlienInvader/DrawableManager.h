#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>


class DrawableManager
{
public:

	DrawableManager();
	
	
	sf::Texture& GetTextureRef(const std::string& texture, const bool repeat, const bool smooth);

	sf::Text CreateText(const std::string& text, const sf::Color color, const int size, const float xPos, const float yPos);

	sf::Text CreateNumber(const int size, const sf::Color color, const float xPos, const float yPos);
	
	void SetFont(const std::string& font);

private:
	//Array of textures used
	std::map< std::string, sf::Texture > m_textures;

	void LoadTexture(const std::string& name);

	sf::Font* m_font;


};

