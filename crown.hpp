#include "asset.hpp"

class Crown: public Asset {
public:
	Crown(): Asset("assets/crown.png") {
		setPos({RWIDTH - 1, RHEIGHT - 1});
	}
};
