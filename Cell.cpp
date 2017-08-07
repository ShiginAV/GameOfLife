#include "Cell.h"

Cell::Cell(int x, int y)
{
	shape_cell.setRadius(CELL_SIZE / 2);
	shape_cell.setFillColor(Color::Green);
	shape_cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
}