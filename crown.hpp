#include "actor.hpp"

class Crown: public Actor {
public:
	Crown(): Actor("assets/crown.png") {
		setPos({RWIDTH - 1, RHEIGHT - 1});
	}
};
