
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
	const float dt = ft.Mark();

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		if (stepCounter >= updatePeriod)
		{
			grid.CheckNeighbors();
			stepCounter -= updatePeriod;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		updatePeriod -= 0.01f;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		updatePeriod += 0.01f;

	}
	
	stepCounter += dt;
}

void Game::ComposeFrame()
{
	grid.Draw(gfx);
}
