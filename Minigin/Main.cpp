#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Engine.h"
#include "Game.h"

dae::Game* loadGame()
{
	dae::Game* pGame{ new dae::Game() };

	return pGame;
}

int main(int, char*[]) {
	dae::Engine engine("../Data/");
	engine.Run(loadGame);
    return 0;
}