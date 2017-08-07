#include "RunGol.h"

void RunGol::run()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	String title{ "<GameOfLife>" };
	RenderWindow window(VideoMode(WIDTH * CELL_SIZE, HEIGHT * CELL_SIZE), title, Style::None | Style::Close, settings);
	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		window.setTitle(title + " CountGenerations: " + std::to_string(generation.get_countGenerations()));
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();		
		}

		if (timer > delay)
		{
			generation.is_dead_or_alive();
			generation.paint(window);
			window.display();
			timer = 0;
		}		
		window.clear();
	}
}

