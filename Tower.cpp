#include "Tower.h"

Tower::Tower()
{
    firerate = 1;
    rotation = 0;
    x = 0;
    y = 0;
}

Tower::Tower(std::vector<Enemy>* memes, int xPos, int yPos)
{
    firerate = 1;
    rotation = 0;
    enemies = memes;
    x = xPos;
    y = yPos;
}

void Tower::Update()
{
    //rotation++;
    if((target == NULL || !target->isEnabled()) && enemies->size() > 0)
    {
        target = &enemies->at(0);
    }
}
