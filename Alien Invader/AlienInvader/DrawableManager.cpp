#include "DrawableManager.h"
#include <iostream>



DrawableManager::DrawableManager()
{
	LoadTexture("background");
	LoadTexture("bullet_enemy");
	LoadTexture("bullet_player");
	LoadTexture("enemy");
	LoadTexture("numeralX");
	LoadTexture("player");
	LoadTexture("player_life");
	LoadTexture("stars");

	std::cout << "Loaded all textures" << std::endl;

}

void DrawableManager::LoadTexture(const std::string& name)
{
	//Load the texture
	sf::Texture m_tex;
	if (!m_tex.loadFromFile("assets/sprites/" + name + ".png"))
	{
		perror("Could not load texture \n");
	}
	std::cout << "Created the " << name << " texture \n";
	//Add it to the list of textures
	this->m_textures[name] = m_tex;

	return;
}

sf::Texture& DrawableManager::GetTextureRef(const std::string& texture, const bool repeat, const bool smooth)
{
	//Function to give a reference to a texture for 
	sf::Texture& m_tex = this->m_textures.at(texture);
	//Set if the texture is supposed to repeat itself inside the sprite
	m_tex.setRepeated(repeat);

	m_tex.setSmooth(smooth);

	return m_tex;

}

sf::Text DrawableManager::CreateText(const std::string& text, const sf::Color color, const int size, const float xPos, const float yPos)
{
	//Create a new text element and set its font, color, size, position and text
	sf::Text newText;
	
	newText.setFont(*m_font);

	newText.setString(text);

	newText.setColor(color);

	newText.setCharacterSize(size);

	newText.setPosition(xPos, yPos);


	return newText;
}

sf::Text DrawableManager::CreateNumber(const int size, const sf::Color color, const float xPos, const float yPos)
{
	//Create a new empty text element and set its font, color, size and position
	sf::Text newText;

	newText.setFont(*m_font);

	newText.setColor(color);

	newText.setCharacterSize(size);

	newText.setPosition(xPos, yPos);

	return newText;
}

void DrawableManager::SetFont(const std::string& font)
{
	//Create a new font and load it based on the inouted string
	m_font = new sf::Font();
	if (!m_font->loadFromFile("assets/fonts/" + font + ".ttf"))
	{
		perror("Font could not be loaded\n");
	}
}




