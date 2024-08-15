#include "Grid.h"
#include <random>

void Grid::Draw(Graphics& gfx) const
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (grid[i][j] == 1)
			{
				gfx.DrawRectDim(i * resolution, j * resolution, resolution, resolution, Colors::White);
			}
		}
	}
}

void Grid::Spawn(std::mt19937& rng)
{
	std::uniform_int_distribution<int> dist(0, 1);

	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			grid[i][j] = dist(rng);
		}
	}

	
}
