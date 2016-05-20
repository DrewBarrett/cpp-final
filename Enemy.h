#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include <allegro5/allegro_color.h>
class Enemy
{
public:
	Enemy(double type, std::vector<double> x, std::vector<double> y);
	int Draw();
	void Enable();
	void TakeDamage(int val) { health -= val;}
	bool IsAlive() { return health > 0;}
	bool isEnabled() {return enabled;}
	double GetX() { return x; }
	double GetY() { return y; }
private:
	int health;
	double speed;
	double x;
	double y;
	bool enabled = false;
	std::vector<double> pathx;
	std::vector<double> pathy;
};

