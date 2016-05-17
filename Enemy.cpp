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
}

void Enemy::Enable()
{
    enabled = true;
    for(int i = 0; i < pathx.size(); i++)
    {
        std::cout << "xy at " << i << " is " << pathx[i] << ", " << pathy[i] << std::endl;
    }
}

void Enemy::Draw()
{
    if(enabled)
    {
        if (x < pathx[pathx.size() - 1])
            x++;
        if (x > pathx[pathx.size() - 1])
            x--;
        if (y < pathy[pathx.size() - 1])
            y++;
        if (y > pathy[pathx.size() - 1])
            y--;
        if(x == pathx[pathx.size() - 1] && y == pathy[pathx.size() - 1])
        {
            pathx.pop_back();
            pathy.pop_back();
        }
        al_draw_filled_circle(x + (70/2), y + (70 /2), 70 / 4, al_color_name("blue"));
        std::cout << "current xy: " << x << ", " << y << std::endl;
    }
}

