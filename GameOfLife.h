#pragma once
#include <iostream>
#include <ctime>
#include "SFML\Graphics.hpp"


const int WIDTH{ 400 };
const int HEIGHT{ 200 };
const char LIVING_CELL{ '*' };
const char DEAD_CELL{ '0' };
const int CELL_SIZE{ 4 };


class GameOfLife
{
	sf::CircleShape shape_cell;
	char generation[HEIGHT][WIDTH];	
	char nextGeneration[HEIGHT][WIDTH];
	int count{ 0 };
	int countGenerations{ 0 };

	int count_neighbors(int, int);	
	void copy_arrays();
public:
	inline int get_countGenerations() { return countGenerations; };
	void is_dead_or_alive();
	GameOfLife();			
	void paint(sf::RenderWindow&);
};