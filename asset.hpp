#pragma once
using namespace sf;

class Asset {
protected:
	Texture texture;
	Sprite sprite;
	int posi = 0, posj = 0;

	Asset() {}

public:
	Asset(const char *name) {
		texture.loadFromFile(name);
		sprite.setTexture(texture);
		sprite.setScale(2, 2);
	}

	void move(int i, int j) {
		posi = i;
		posj = j;
	}

	const Sprite& getSprite() {
		sprite.setPosition(posi * R, posj * R);
		return sprite;
	}
};
