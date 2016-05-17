#pragma once
#include <string>
#include <vector>
class Enemy
{
public:
	Enemy(int type, std::vector<int> x, std::vector<int> y);
private:
	int health;
	int speed;
	int x;
	int y;
	std::vector<int> pathx;
	std::vector<int> pathy;
};

