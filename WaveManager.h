#pragma once
#include "Enemy.h"
#include <vector>
class WaveManager
{
public:
	WaveManager();
	void AdvanceWave(std::vector<int>, std::vector<int>);
	void update();
private:
	int wave = 0;
	std::vector<Enemy> enemies;
};
