#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;


const int CELL_SIZE{ 10 };

class Cell
{
	CircleShape shape_cell;
public:
	inline CircleShape get_cellshape(){ return shape_cell; }
	Cell(int x, int y);
};