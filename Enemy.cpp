#include "Enemy.h"



Enemy::Enemy(int type, std::vector<int> x, std::vector<int> y)
{
    //basic enemy
	if (type == 1)
	{
		health = 10;
		speed = 1;
	}
}

