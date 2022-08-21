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
};
