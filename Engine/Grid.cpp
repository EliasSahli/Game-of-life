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

void Grid::SpawnSpecific()
{
	grid[40][30] = 1;
	grid[39][30] = 1;
	grid[40][29] = 1;
	grid[40][31] = 1;
	grid[41][31] = 1;
}

void Grid::CheckNeighbours()
{
}
