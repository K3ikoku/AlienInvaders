#pragma once
#include <SFML\Graphics.hpp>

class GUIManager
{
public:
	GUIManager(sf::Font* font, sf::Color color);
	~GUIManager();

	sf::Text CreateText(std::string text, int size, float xPos, float yPos);

	sf::Text CreateNumber(int size, float xPos, float yPos);


private:
	sf::Font* m_font;
	sf::Color m_color;

};

