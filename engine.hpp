#include "include.hpp"
#include "backtiles.hpp"
#include "bombs.hpp"
#include "crown.hpp"
#include "hero.hpp"

using namespace sf;

class Engine {
private:
	RenderWindow window;
	BacktileBundle backtiles;
	Hero hero;
	Crown crown;
	BombBundle bombs;

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

	void lose() {
		cout << "YOU LOSE!" << endl;
		window.close();
	}

	void preUpdate() {

	}

	void draw() {
		window.clear();
		backtiles.draw(window);
		bombs.draw(window);
		crown.draw(window);
		hero.draw(window);
		window.display();
	}

	void postUpdate() {
		if (hero.collide(&crown)) win();
		if (bombs.collide(&hero)) lose();
	}

	void start() {
		while (window.isOpen()) {
			input();
			preUpdate();
			draw();
			postUpdate();
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
