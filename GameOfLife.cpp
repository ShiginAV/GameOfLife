#include "GameOfLife.h"

GameOfLife::GameOfLife()
{
	srand(time(0));
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{		
			int num = rand() % 2;
			char cell = DEAD_CELL;
			if (num) cell = LIVING_CELL;
			//generation[y][x] = cell;	
			*(*(generation + y) + x) = cell;
		}
	}
}

//поиск количества соседей
int GameOfLife::count_neighbors(int y, int x)
{
	count = 0;
	for (int dy = -1; dy < 2; ++dy)
		for (int dx = -1; dx < 2; ++dx)
		{
			int nY = y + dy;
			int nX = x + dx;
			if (nX < 0 || nY < 0 || nX > WIDTH - 1 || nY > HEIGHT - 1) continue;
			//if (generation[nY][nX] == LIVING_CELL) count++;
			if (*(*(generation + nY) + nX) == LIVING_CELL) count++;
		}
	//if (generation[y][x] == LIVING_CELL) count--;
	if (*(*(generation + y) + x) == LIVING_CELL) count--;

	return count;
}

//копирование массивов
void GameOfLife::copy_arrays()
{
	for (int x = 0; x < HEIGHT; ++x)
		for (int y = 0; y < WIDTH; ++y)
			//generation[x][y] = nextGeneration[x][y];
			*(*(generation + x) + y) = *(*(nextGeneration + x) + y);
}

//появление или уничтожение клетки
void GameOfLife::is_dead_or_alive()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{			
			count = count_neighbors(y, x);
			/*if (count == 3) nextGeneration[y][x] = LIVING_CELL;
			if(count > 3 || count < 2) nextGeneration[y][x] = DEAD_CELL;*/
			if (count == 3) *(*(nextGeneration + y) + x) = LIVING_CELL;
			if (count > 3 || count < 2) *(*(nextGeneration + y) + x) = DEAD_CELL;
		}
	}
	copy_arrays();
	countGenerations++;
}

//вывести на экран
void GameOfLife::paint(RenderWindow &win)
{
	for (int y = 0; y < HEIGHT; ++y)	
		for (int x = 0; x < WIDTH; ++x)		
			//if (generation[y][x] == LIVING_CELL)
			if (*(*(generation + y) + x) == LIVING_CELL)
			{
				Cell cell(x, y);
				win.draw(cell.get_cellshape());
			}
}

