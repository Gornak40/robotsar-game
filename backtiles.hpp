#include "bundle.hpp"

class BacktileBundle: public Bundle {
public:
	BacktileBundle(): Bundle("assets/backtile.png") {
		for (int i = 0; i < RWIDTH; ++i)
			for (int j = 0; j < RHEIGHT; ++j)
				poses.emplace_back(i, j);
	}
};
