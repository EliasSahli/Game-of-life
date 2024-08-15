
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Grid.h"
#include <random>
#include "FrameTimer.h"
#include "Board.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();

private:
	MainWindow& wnd;
	Graphics gfx;

	std::mt19937 rng;
	FrameTimer ft;
	Grid grid;
	Board bd;

	float stepCounter = 0.0f;
	float updatePeriod = 0.004f;
	bool drawLines = false;
};