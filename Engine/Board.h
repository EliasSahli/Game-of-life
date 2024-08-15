#pragma once

#include "Graphics.h"
#include "Grid.h"
#include "Colors.h"

class Board
{
public:
	Grid grid;

	void Draw(Graphics& gfx) const
	{
		int resolution = grid.GetResolution();
		for (int x = 0; x < Graphics::ScreenWidth; x += resolution)
		{
			for (int i = 0; i < Graphics::ScreenHeight; i++)
			{
				gfx.PutPixel(x, i, Colors::LightGray);
			}
		}
		for (int y = 0; y < Graphics::ScreenHeight; y += resolution)
		{
			for (int i = 0; i < Graphics::ScreenWidth; i++)
			{
				gfx.PutPixel(i, y, Colors::LightGray);
			}
		}
	}
};