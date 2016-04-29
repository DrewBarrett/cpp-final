#include "GUI.h"
#include "TowerMenu.h"

GUI::GUI()
{
    mapgrid = MapGrid();
    towermenu = TowerMenu();
    descriptionbox = DescriptionBox();
}

void GUI::Draw(ALLEGRO_MOUSE_STATE state)
{
    mapgrid.draw(state);
    towermenu.draw(state);
    descriptionbox.Draw();
}

void GUI::MouseClicked()
{
    GridSquare *gs = mapgrid.GetHover();
    if(gs != NULL){
        mapgrid.SetClicked();
        gs->SetClicked(true);
    }
}

