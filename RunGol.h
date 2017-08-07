#pragma once
#include "GameOfLife.h"

constexpr float delay{ 0.1f };

class RunGol
{
	float timer{ 0 };
	GameOfLife generation;
public:
	void run();
};