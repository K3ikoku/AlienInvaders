#include "GUIManager.h"



GUIManager::GUIManager(sf::Font* font, sf::Color color):
	m_font(font),
	m_color(color)
{
}


GUIManager::~GUIManager()
{
}

sf::Text GUIManager::CreateText(std::string text, int size,float xPos, float yPos)
{
	sf::Text newText;

	newText.setFont(*m_font);

	newText.setColor(m_color);

	newText.setString(text);

	newText.setCharacterSize(size);

	newText.setPosition(xPos, yPos);

	return newText;
}

sf::Text GUIManager::CreateNumber(int size, float xPos, float yPos)
{
	sf::Text newText;
	
	newText.setFont(*m_font);

	newText.setColor(m_color);

	newText.setCharacterSize(size);

	newText.setPosition(xPos, yPos);

	return newText;

}
