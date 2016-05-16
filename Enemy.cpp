#include "Enemy.h"



Enemy::Enemy(std::string type)
{
	if (type == "basic") 
	{
		health = 10;
		speed = 1;
	}
}

