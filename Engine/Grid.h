#pragma once

#include "Graphics.h"
#include <random>


class Grid
{
public:
	void Draw(Graphics& gfx) const;
	void Spawn(std::mt19937& rng);

private:
	static constexpr int resolution = 10;
	static constexpr int columns = Graphics::ScreenWidth / resolution;
	static constexpr int rows = Graphics::ScreenHeight / resolution;
	int grid[columns][rows];
};