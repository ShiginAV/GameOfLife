#include "RunGol.h"

void RunGol::run()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::String title{ "<GameOfLife>" };
	sf::RenderWindow window(sf::VideoMode(WIDTH * CELL_SIZE, HEIGHT * CELL_SIZE), title, sf::Style::None | sf::Style::Close, settings);
	sf::Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		window.setTitle(title + " CountGenerations: " + std::to_string(generation.get_countGenerations()));
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
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

