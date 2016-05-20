#include "Tower.h"

Tower::Tower()
{
    firerate = 1;
    rotation = 0;
    x = 0;
    y = 0;
}

Tower::Tower(std::vector<Enemy>* memes, int xPos, int yPos, ALLEGRO_SAMPLE* sample, std::string type)
{
	shootsound = sample;
	if (type == "super") {
		firerate = 1;
		color = al_color_name("red");
	}
	else if (type == "green")
	{
		firerate = .5;
		color = al_color_name("green");
	}
	else if (type == "orange")
	{
		firerate = .75;
		color = al_color_name("orange");
	}
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
		//std::cout << "size of enemy array" << enemies->size() << std::endl;
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
			al_play_sample(shootsound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			al_draw_line(x,y,target->GetX() + 70 / 2 ,target->GetY() + 70 / 2, color, 5);
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
