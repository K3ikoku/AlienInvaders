#include <SFML/Window.hpp>
#include <SFML\Graphics.hpp>
#include "Application.h"

int main()
{
	sf::Window m_window(sf::VideoMode(640, 955), "My window");

	// run the program as long as the window is open
	while (m_window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event m_event;
		while (m_window.pollEvent(m_event))
		{
			Application* application = new Application();

			application->awake();


			// "close requested" event: we close the window
			if (m_event.type == sf::Event::Closed)
				m_window.close();
		}
	}

	return 0;
}