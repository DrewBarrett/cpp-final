#pragma once
#include <string>
class Enemy
{
public:
	Enemy(std::string type);
private:
	int health;
	int speed;
	int x;
	int y;
};

