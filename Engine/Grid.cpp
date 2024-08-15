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
				gfx.DrawRectDim((i * resolution) + 1, (j * resolution) + 1, resolution - 1, resolution - 1, Colors::White);
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
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			grid[i][j] = 0;
		}
	}

	grid[40][30] = 1;
	grid[39][30] = 1;
	grid[40][29] = 1;
	grid[40][31] = 1;
	grid[41][31] = 1;
}

void Grid::CheckNeighbors()
{
	// Make a copy of grid
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			nextGrid[i][j] = grid[i][j];
		}
	}

	// loop over all neighbours for every specific cell
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{

			int neighbors = 0;

			for (int x = -1; x < 2; x++)	// loops over all neighbors
			{
				for (int y = -1; y < 2; y++)
				{
					int col = (x + i + columns) % columns;
					int row = (y + j + rows) % rows;

					neighbors += grid[col][row];
				}
			}

			neighbors -= grid[i][j];

			if (grid[i][j] == 0 && neighbors == 3)
			{
				nextGrid[i][j] = 1;
			}
			else if (grid[i][j] == 1 && (neighbors < 2 || neighbors >3))
			{
				nextGrid[i][j] = 0;
			}
			else
			{
				nextGrid[i][j] = grid[i][j];
			}
		}
	}
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			grid[i][j] = nextGrid[i][j];
		}
	}
}
