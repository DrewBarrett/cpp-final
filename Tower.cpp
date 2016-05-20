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
	if (enemies == NULL)
	{
		//printf("NULL enemies vector! Maybe the wave hasnt started...\n");
	}
	if (enemies != NULL && enemies->size() > 0 && (target == NULL || !target->isEnabled()))
	{
		//std::cout << "target set" << std::endl;
		target = &enemies->at(0);
	}
	if (target != NULL && target->isEnabled()) {
		//tower allready knows its center while enemy only knows top left
		double adjacent = -1*((target->GetY() + 70/2) - y);
		double opposite = ((target->GetX() + 70/2) - x);
		//rotation = atan(opposite / adjacent);
		rotation = atan2(opposite,adjacent);
		//std::cout << "Rotation set: " << opposite << " " << adjacent << " " << rotation << std::endl;

        if(cooldown <= 0)
        {
            cooldown = 1;
            target->TakeDamage(1);
            target = NULL;//retarget after firing in case enemy is out of range
        }
		else{
            cooldown -= firerate * .1;
		}
		/*if(!target->IsAlive())
        {
            target = NULL;
        }*/
	}
}
