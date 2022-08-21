#pragma once

#include "actor.hpp"

using namespace sf;

class Bundle {
protected:
	vector<Vector2i> poses;
	Actor actor;

	Bundle() {}

public:
	Bundle(const char *name): actor(name) {}

	void draw(RenderWindow &window) {
		for (const auto &p: poses) {
			actor.setPos(p);
			actor.draw(window);
		}
	}

	void push(const Vector2i &p) {
		poses.push_back(p);
	}

	bool pop(const Vector2i &p) {
		auto it = find(poses.begin(), poses.end(), p);
		if (it == poses.end()) return false;
		poses.erase(it);
		return true;
	}

	bool pop(const Actor *obj) {
		return pop(obj -> getPos());
	}

	bool collide(const Vector2i &p) const {
		auto it = find(poses.begin(), poses.end(), p);
		return it != poses.end();
	}

	bool collide(const Actor *obj) const {
		return collide(obj -> getPos());
	}
};
