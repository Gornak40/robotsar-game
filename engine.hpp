#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "backtile.hpp"
#include "hero.hpp"

using namespace sf;

class Engine {
private:
	RenderWindow window;
	Backtile backtile;
	Hero hero;

	void input() {	
		for (Event event; window.pollEvent(event);) {
			switch (event.type) {
				case Event::Closed:
					window.close();
					break;
				case Event::KeyPressed:
					switch (event.key.code) {
						case Keyboard::W:
							hero.moveUp();
							break;
						case Keyboard::S:
							hero.moveDown();
							break;
						case Keyboard::D:
							hero.moveRight();
							break;
						case Keyboard::A:
							hero.moveLeft();
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}	
		}
	}

	void update() {
		window.clear(Color::Blue);
		for (int i = 0; i < RWIDTH; ++i)
			for (int j = 0; j < RHEIGHT; ++j) {
				backtile.move(i, j);
				window.draw(backtile.getSprite());
			}
		window.draw(hero.getSprite());
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