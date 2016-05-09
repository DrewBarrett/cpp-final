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
    if(!mapgrid.IsClicked()){
        towermenu.disable();
    }else{
        towermenu.enable();
    }
    towermenu.draw(state);
    descriptionbox.Draw(title, description);
}

void GUI::MouseClicked()
{
    GridSquare *gs = mapgrid.GetHover();
    if(gs != NULL){
        mapgrid.SetClicked();
        gs->SetClicked(true);
    }else if (towermenu.click()){

    }else{
        //deselect gridsquare
        mapgrid.SetClicked();
    }
}

