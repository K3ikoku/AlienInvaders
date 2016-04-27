#include <SFML/Window.hpp>
#include <SFML\Graphics.hpp>
#include "Application.h"

int main()
{

	
			Application* app = new Application();

			app->start();
			// run the program as long as the window is open
			while (app->m_window.isOpen())
			{
				// check all the window's events that were triggered since the last iteration of the loop
				sf::Event m_event;
				while (app->m_window.pollEvent(m_event))
				{
					app->gameLoop();
				
					// "close requested" event: we close the window
					if (m_event.type == sf::Event::Closed)
						app->m_window.close();
				}

	return 0;
}