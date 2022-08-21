#pragma once

#include "include.hpp"

using namespace std;
using namespace sf;

class Actor {
protected:
	Texture texture;
	Sprite sprite;
	Vector2i pos = {0, 0};

public:
	Actor() {}

	Actor(const char *name) {
		texture.loadFromFile(name);
		sprite.setTexture(texture);
		sprite.setScale(2, 2);
	}

	void setPos(const Vector2<int> &p) {
		pos = p;
	}

	const Vector2<int>& getPos() const {
		return pos;
	}

	void draw(RenderWindow &window) {
		sprite.setPosition(pos.x * R, pos.y * R);
		window.draw(sprite);
	}

	bool collide(const Vector2i &p) const {
		return getPos() == p;
	}

	bool collide(const Actor *obj) const {
		return getPos() == obj -> getPos();
	}
};
