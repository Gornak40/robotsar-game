#include "actor.hpp"

class Hero: public Actor {
public:
	Hero(): Actor("assets/hero.png") {}

	void moveUp() {
		if (--pos.y == -1) pos.y = 0;
	}

	void moveDown() {
		if (++pos.y == RHEIGHT) pos.y = RHEIGHT - 1;
	}

	void moveRight() {
		if (++pos.x == RWIDTH) pos.x = RWIDTH - 1;
	}

	void moveLeft() {
		if (--pos.x == -1) pos.x = 0;
	}

	bool tick(const Event &event) {
		if (event.type != Event::KeyPressed) return false;
		switch (event.key.code) {
			case Keyboard::W:
			moveUp();
			return true;
			case Keyboard::S:
			moveDown();
			return true;
			case Keyboard::D:
			moveRight();
			return true;
			case Keyboard::A:
			moveLeft();
			return true;
			default:
			return false;
		}
	}
};
