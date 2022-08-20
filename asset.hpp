#pragma once

#include "include.hpp"

using namespace std;
using namespace sf;

class Asset {
protected:
	Texture texture;
	Sprite sprite;
	Vector2<int> pos = {0, 0};

	Asset() {}

public:
	Asset(const char *name) {
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

	const Sprite& getSprite() {
		sprite.setPosition(pos.x * R, pos.y * R);
		return sprite;
	}
};
