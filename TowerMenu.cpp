#include "TowerMenu.h"

TowerMenu::TowerMenu()
{
    //ctor
}

void TowerMenu::draw(){
    al_draw_rounded_rectangle(10, 10, 150, ScreenHeight-200, 0, 0, al_color_name("white"), 5);
}
