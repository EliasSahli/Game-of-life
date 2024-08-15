
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng(std::random_device()())
{
	//grid.Spawn(rng);
	grid.SpawnSpecific();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	grid.CheckNeighbours();
}

void Game::ComposeFrame()
{
	grid.Draw(gfx);
}
