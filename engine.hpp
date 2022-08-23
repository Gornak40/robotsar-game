#include "include.hpp"
#include "backtiles.hpp"
#include "bombs.hpp"
#include "crown.hpp"
#include "hero.hpp"
#include "enemy.hpp"

using namespace sf;

class Engine {
private:
	RenderWindow window;
	BacktileBundle *backtiles = new BacktileBundle();
	Hero *hero = new Hero();
	Crown *crown = new Crown();
	BombBundle *bombs = new BombBundle();
	Enemy *enemy = new Enemy();

	void input() {	
		for (Event event; window.pollEvent(event);) {
			if (event.type == Event::Closed) window.close();
			if (hero -> tick(event)) enemy -> tick(hero);
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

	void draw() {
		window.clear();
		backtiles -> draw(window);
		bombs -> draw(window);
		crown -> draw(window);
		hero -> draw(window);
		enemy -> draw(window);
		window.display();
	}

	void update() {
		if (hero -> collide(enemy)) lose();
		if (hero -> collide(crown)) win();
		if (bombs -> pop(hero)) lose();
		if (bombs -> pop(enemy)) enemy -> stop();
	}

	void start() {
		while (window.isOpen()) {
			input();
			draw();
			update();
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
