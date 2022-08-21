#include "bundle.hpp"

class BombBundle: public Bundle {
public:
	BombBundle(): Bundle("assets/bomb.png") {
		while (poses.size() < NUMBOMBS) {
			Vector2i p = {rand() % (RWIDTH - 2) + 1, rand() % (RHEIGHT - 2) + 1};
			if (!collide(p)) poses.push_back(p);
		}
	}
};
