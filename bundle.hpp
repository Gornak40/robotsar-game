#include "asset.hpp"

using namespace sf;

class Bundle {
protected:
	vector<Vector2i> poses;
	Asset asset;

	Bundle() {}

public:
	Bundle(const char *name): asset(name) {}

	void draw(RenderWindow &window) {
		for (const auto &p: poses) {
			asset.setPos(p);
			asset.draw(window);
		}
	}

	bool collide(const Asset *obj, bool erase=true) {
		auto it = find(poses.begin(), poses.end(), obj -> getPos());
		if (it == poses.end()) return false;
		if (erase) poses.erase(it);
		return true;
	}
};
