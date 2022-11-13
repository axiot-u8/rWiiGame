#include "Game/MainProject.h"

int main()
{
	Game::mainProj = new Game::MainProject();
	Game::mainProj->run();
	delete Game::mainProj;

	exit(EXIT_SUCCESS);
}