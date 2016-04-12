#include "TowerMenu.h"

TowerMenu::TowerMenu()
{
    //ctor
}

void TowerMenu::draw(){
    al_draw_rounded_rectangle(10, ScreenHeight - 200, ScreenWidth - 10, ScreenHeight - 10, 7, 7, al_color_name("white"), 5);
}
