#include <Windows.h>
#include "Game.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main()
{
	//Initiate the game loop
	Game* m_game = new Game;

	m_game->GameLoop();

	return 0;
	
	
			
return 0;
}