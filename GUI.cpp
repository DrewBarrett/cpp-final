#include "GUI.h"

GUI::GUI()
{
    mapgrid = MapGrid();
    towermenu = TowerMenu();
    descriptionbox = DescriptionBox();
}

void GUI::Draw(ALLEGRO_MOUSE_STATE state)
{
    mapgrid.draw(state);
    towermenu.draw();
    descriptionbox.Draw();
}

