#include "actor.hpp"

class Enemy: public Actor {
public:
	int timer = 0;

	Enemy(): Actor("assets/enemy.png") {
		setPos({RWIDTH - 1, 0});
	}

	void tick(const Actor *obj) {
		if (timer) {
			if (timer-- == 1) show();
			return;
		}
		Vector2i p = obj -> getPos();
		if (pos.x < p.x) ++pos.x;
		if (pos.x > p.x) --pos.x;
		if (pos.y < p.y) ++pos.y;
		if (pos.y > p.y) --pos.y;
	}

	void stop() {
		hide();
		timer = TIMEWAIT;
	}
};
