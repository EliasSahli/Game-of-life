#pragma once

#include "Graphics.h"
#include <random>


class Grid
{
public:
	void Draw(Graphics& gfx) const;
	void Spawn(std::mt19937& rng);
	void SpawnSpecific();
	void CheckNeighbors();
	int GetResolution()const ;

	//int GetColums() const;
	//int GetRows() const;

private:
	static constexpr int resolution = 5;

	// the grid is 80 * 60 squares
	static constexpr int columns = Graphics::ScreenWidth / resolution;
	static constexpr int rows = Graphics::ScreenHeight / resolution;

	int grid[columns][rows];
	int nextGrid[columns][rows];
};