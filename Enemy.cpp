#include "Enemy.h"



Enemy::Enemy(int type, std::vector<int> x1, std::vector<int> y1)
{
    //basic enemy
    pathx = x1;
    pathy = y1;
    x = pathx[pathx.size()];
    y = pathy[pathx.size()];
	if (type == 1)
	{
		health = 10;
		speed = 1;
	}
}

void Enemy::Enable()
{
    enabled = true;
}

void Enemy::Draw()
{
    if(enabled)
    {
        if (x < pathx[pathx.size()])
            x++;
        if (x > pathx[pathx.size()])
            x--;
        if (y < pathy[pathx.size()])
            y++;
        if (y > pathy[pathx.size()])
            y--;
        if(x == pathx[pathx.size()] && y == pathy[pathx.size()])
        {
            pathx.pop_back();
            pathy.pop_back();
        }
        al_draw_filled_circle(x + (70/2), y + (70 /2), 70 / 4, al_color_name("blue"));
    }
}

