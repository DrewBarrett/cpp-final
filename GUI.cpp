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
    std::string title;
    std::string description;
    mapgrid.draw(state, &title, &description);
    towermenu.draw(state);
    descriptionbox.Draw(title, description);
}

void GUI::MouseClicked()
{
    GridSquare *gs = mapgrid.GetHover();
    if(gs != NULL){
        mapgrid.SetClicked();
        gs->SetClicked(true);
        if (gs->Getoccupied() == 0)
        {
            towermenu.enable();
        }
        else
        {
            towermenu.disable();
        }
    }else if (towermenu.click()){
        mapgrid.GetClicked()->Setoccupied(3);
    }else{
        //deselect gridsquare
        mapgrid.SetClicked();
        towermenu.disable();
    }
}

