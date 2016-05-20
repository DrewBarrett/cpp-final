#include "GUI.h"
#include "TowerMenu.h"

GUI::GUI()
{
	//this is redundant but if it works dont fix it
    mapgrid = MapGrid(wavemanager.GetEnemies());
    //towermenu = TowerMenu();
    //descriptionbox = DescriptionBox();
	mapgrid.Pathfind();
	//mapgrid.setEnemies();
}

void GUI::Draw(ALLEGRO_MOUSE_STATE state)
{
    std::string title;
    std::string description;

    mapgrid.draw(state, &title, &description);
    towermenu.draw(state);
    descriptionbox.Draw(title, description);
	wavepanel.Draw(state);
	//wave manager needs to be called last so enemies show up above grass!
	wavemanager.update();
}

void GUI::MouseClicked()
{
    GridSquare *gs = mapgrid.GetHover();
    if(gs != NULL){
        mapgrid.SetClicked();
        gs->SetClicked(true);
		//mapgrid.Pathfind();
        if (gs->Getoccupied() == 0)
        {
            towermenu.enable();
        }
        else
        {
            towermenu.disable();
        }
    }else if (towermenu.click() && towermenu.GetEnabled()){
        mapgrid.GetClicked()->Setoccupied(3);
		towermenu.disable();
		if (mapgrid.GetClicked()->IsPath() && !mapgrid.Pathfind()) {
			//TODO: only call pathfinding if the tile is in the way of the path.
			//building a tower here would cause the pathfinding to error! Hopefully because there is no available path...
			mapgrid.GetClicked()->Setoccupied(0);
			towermenu.enable();
		}
		
    }
    else if (wavepanel.click())
    {
        mapgrid.GetPath(&pathx, &pathy);
        wavemanager.AdvanceWave(pathx, pathy);
    }
    else
    {
        //deselect gridsquare
        mapgrid.SetClicked();
        towermenu.disable();
    }
}

