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
	wavepanel.setWavePointer(wavemanager.GetWavePointer());
}

void GUI::Draw(ALLEGRO_MOUSE_STATE state)
{
    std::string title;
    std::string description;

    mapgrid.draw(state, &title, &description, wavemanager.GetWaveInProgress());
    towermenu.draw(state, &title, &description, money);
    descriptionbox.Draw(title, description);
	wavepanel.Draw(state, money, health);
	//wave manager needs to be called last so enemies show up above grass!
	wavemanager.update(&money, &health);
	if(!wavemanager.GetWaveInProgress())
	{
	    wavepanel.enable();
	}
}

void GUI::MouseClicked()
{
    GridSquare *gs = mapgrid.GetHover();
    if(gs != NULL){
        mapgrid.SetClicked();
        gs->SetClicked(true);
		//mapgrid.Pathfind();
        if (gs->Getoccupied() == 0 && !wavemanager.GetWaveInProgress())
        {
            towermenu.enable();
        }
        else
        {
            towermenu.disable();
        }
    }else if (towermenu.click() && towermenu.GetEnabled() && !wavemanager.GetWaveInProgress() && towermenu.getCost() <= money){
		if (towermenu.GetHover() == "Dale")
		{
			mapgrid.GetClicked()->Setoccupied(3);
		}
		else if (towermenu.GetHover() == "green")
		{
			mapgrid.GetClicked()->Setoccupied(5);
		}
		else if (towermenu.GetHover() == "orange")
		{
			mapgrid.GetClicked()->Setoccupied(6);
		}
		else if (towermenu.GetHover() == "wall")
		{
			mapgrid.GetClicked()->Setoccupied(2);
		}
		money -= towermenu.getCost();
		towermenu.disable();
		if (mapgrid.GetClicked()->IsPath() && !mapgrid.Pathfind()) {
			//TODO: only call pathfinding if the tile is in the way of the path.
			//building a tower here would cause the pathfinding to error! Hopefully because there is no available path...
			mapgrid.GetClicked()->Setoccupied(0);
			towermenu.enable();
			money += towermenu.getCost();
		}

    }
    else if (wavepanel.click() && !wavemanager.GetWaveInProgress())
    {
        mapgrid.GetPath(&pathx, &pathy);
        wavemanager.AdvanceWave(pathx, pathy);
        wavepanel.disable();
    }
    else
    {
        //deselect gridsquare
        mapgrid.SetClicked();
        towermenu.disable();
    }
}

