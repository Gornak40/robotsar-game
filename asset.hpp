#pragma once
using namespace sf;

class Asset {
protected:
	Texture texture;
	Sprite sprite;

	Asset() {}

public:
	Asset(const char *name) {
		texture.loadFromFile(name);
		sprite.setTexture(texture);
		sprite.setScale(2, 2);
	}

	void move(int i, int j) {
		sprite.setPosition(R * i, R * j);
	}

	Sprite getSprite() {
		return sprite;
	}
};
