#pragma once
#include <iostream>
#include <ctime>
#include "Cell.h"

using namespace std;

const int WIDTH{ 70 };
const int HEIGHT{ 70 };
const char LIVING_CELL{ '*' };
const char DEAD_CELL{ '0' };

class GameOfLife
{
	char generation[HEIGHT][WIDTH];	
	char nextGeneration[HEIGHT][WIDTH];
	int count{ 0 };
	int countGenerations{ 0 };

	int count_neighbors(int x, int y);	
	void copy_arrays();
public:
	inline int get_countGenerations() { return countGenerations; };
	void is_dead_or_alive();
	GameOfLife();			
	void paint(RenderWindow&);
};