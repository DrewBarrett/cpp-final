#include "TowerMenu.h"

TowerMenu::TowerMenu()
{
    //Button testTower = Button(15, 15, al_load_bitmap("greenTower.png"));
    for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            grid[i][j] = Button(13+(j*(135/GridWidth)), 13+(i*(135/GridWidth)), 135/GridWidth,al_load_bitmap("greenTower.png"));
        }
    }
}

void TowerMenu::draw(ALLEGRO_MOUSE_STATE mouse)
{
    al_draw_rounded_rectangle(10, 10, 150, ScreenHeight-200, 0, 0, al_color_name("white"), 5);
    for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            grid[i][j].draw(mouse);
        }
    }
}
