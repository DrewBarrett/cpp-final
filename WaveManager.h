#pragma once
#include "Enemy.h"
#include <vector>
class WaveManager
{
public:
	WaveManager();
	void AdvanceWave(std::vector<int>, std::vector<int>);
	void update(int*,int*);
	bool GetWaveInProgress() {return waveInProgress;}
	int* GetWavePointer() {return &wave;}
	std::vector<Enemy>* GetEnemies() { return &enemies; }
private:
	int wave = 0;
	int timer = 0;
	std::vector<Enemy> enemies;
	int numEnabled = 0;
	int numGone = 0;
	bool waveInProgress = false;
};

