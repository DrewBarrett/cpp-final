#include "Enemy.h"



Enemy::Enemy(int type, std::vector<int> x1, std::vector<int> y1)
{
    //basic enemy
    pathx = x1;
    pathy = y1;
    x = pathx[pathx.size() - 1];
    y = pathy[pathy.size() - 1];
	if (type == 1)
	{
		health = 10;
		speed = 1;
	}
	if (type == 2)
	{
		health = 20;
		speed = 2;
	}
}

void Enemy::Enable()
{
    enabled = true;
    /*for(int i = 0; i < pathx.size(); i++)
    {
        std::cout << "xy at " << i << " is " << pathx[i] << ", " << pathy[i] << std::endl;
    }*/
}

int Enemy::Draw()
{
    if (pathx.size() == 0)
    {
        enabled = false;
        return 2;
    }
    if (health <= 0)
    {
        return 3;
    }
    if(enabled)
    {

		if (x < pathx[pathx.size() - 1])
            x++;
        else if (x > pathx[pathx.size() - 1])
            x--;
        if (y < pathy[pathy.size() - 1])
            y++;
        else if (y > pathy[pathy.size() - 1])
            y--;
        al_draw_filled_circle(x + (70/2), y + (70 /2), 70 / 4, al_color_name("blue"));
        if(x == pathx[pathx.size() - 1] && y == pathy[pathx.size() - 1])
        {
            pathx.pop_back();
            pathy.pop_back();
            //return 1;
        }


        //std::cout << "current xy: " << x << ", " << y << std::endl;
    }
    return 0;
}

