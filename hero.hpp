#include "asset.hpp"

class Hero: public Asset {
public:
	Hero(): Asset("assets/hero.png") {}

	void moveUp() {
		if (--posj == -1) posj = 0;
	}

	void moveDown() {
		if (++posj == RHEIGHT) posj = RHEIGHT - 1;
	}

	void moveRight() {
		if (++posi == RWIDTH) posi = RWIDTH - 1;
	}

	void moveLeft() {
		if (--posi == -1) posi = 0;
	}
};
