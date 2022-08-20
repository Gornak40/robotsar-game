#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "backtile.hpp"

using namespace sf;

class Engine {
private:
	RenderWindow window;
	Backtile backtile;

	void input() {	
		for (Event event; window.pollEvent(event);) {
			if (event.type == Event::Closed) window.close();
		}
	}

	void update() {
		window.clear(Color::Blue);
		for (int i = 0; i < RWIDTH; ++i)
			for (int j = 0; j < RHEIGHT; ++j) {
				backtile.move(i, j);
				window.draw(backtile.getSprite());
			}
	}

	void draw() {
		window.display();
	}

	void start() {
		while (window.isOpen()) {
			input();
			update();
			draw();
		}
	}

public:
	Engine() {
		window.create(VideoMode(WIDTH, HEIGHT), "RoboTrar");
		window.setFramerateLimit(FPS);
		window.setVerticalSyncEnabled(VERTSYNC);
		start();
	}
};