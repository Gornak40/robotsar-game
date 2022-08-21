#include "include.hpp"
#include "backtiles.hpp"
#include "hero.hpp"
#include "crown.hpp"

using namespace sf;

class Engine {
private:
	RenderWindow window;
	BacktileBundle backtiles;
	Hero hero;
	Crown crown;

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

	void win() {
		cout << "YOU WIN!" << endl;
		window.close();
	}

	void update() {

	}

	void draw() {
		window.clear();
		backtiles.draw(window);
		crown.draw(window);
		hero.draw(window);
		window.display();
	}

	void check() {
		if (hero.collide(&crown)) win();
	}

	void start() {
		while (window.isOpen()) {
			input();
			update();
			draw();
			check();
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
