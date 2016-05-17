#pragma once
#include <string>
#include <vector>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include <allegro5/allegro_color.h>
class Enemy
{
public:
	Enemy(int type, std::vector<int> x, std::vector<int> y);
	void Draw();
	void Enable();
private:
	int health;
	int speed;
	int x;
	int y;
	bool enabled = false;
	std::vector<int> pathx;
	std::vector<int> pathy;
};

