#include "Enemy.h"



Enemy::Enemy(double type, std::vector<double> x1, std::vector<double> y1)
{
    //basic enemy
    pathx = x1;
    pathy = y1;
    x = pathx[pathx.size() - 1];
    y = pathy[pathy.size() - 1];
	speed = type * 1.10;
	std::cout << "speed" << speed << std::endl;
	health = 10;
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
		bool left = false;
		bool right = false;
		bool up = false;
		bool down = false;
		std::cout << "current xy: " << x << ", " << y << " " << pathx[pathx.size() - 1] << ", " << pathy[pathy.size() - 1] << std::endl;
		if (x < pathx[pathx.size() - 1])
		{
			x += speed;
			right = true;
			std::cout << "moving right" << std::endl;
		}
		else if (x > pathx[pathx.size() - 1])
		{
			x -= speed;
			left = true;
			std::cout << "moving left" << std::endl;
		}
		if (y < pathy[pathy.size() - 1])
		{
			y += speed;
			down = true;
			std::cout << "moving down" << std::endl;
		}
		else if (y > pathy[pathy.size() - 1])
		{
			y -= speed;
			up = true;
			std::cout << "moving up" << std::endl;
		}
            
        al_draw_filled_circle(x + (70/2), y + (70 /2), 70 / 4, al_color_name("blue"));
        
		//if(x == pathx[pathx.size() - 1] && y == pathy[pathx.size() - 1])
        //{
        //    pathx.pop_back();
        //    pathy.pop_back();
        //    //return 1;
        //}
		if ((right && x >= pathx[pathx.size() - 1]) || (left && x <= pathx[pathx.size() - 1]) || (x == pathx[pathx.size() -1] && y == pathy[pathy.size()-1]))
		{
			x = pathx[pathx.size() - 1];
			pathx.pop_back();
			pathy.pop_back();
			return 1;
		}
		else if (up && y <= pathy[pathy.size() - 1])
		{
			y = pathy[pathy.size() - 1];
			pathx.pop_back();
			pathy.pop_back();
			return 1;
		}
		else if (down && y >= pathy[pathy.size() - 1])
		{
			y = pathy[pathy.size() - 1];
			pathx.pop_back();
			pathy.pop_back();
			return 1;
		}


        
    }
    return 0;
}

