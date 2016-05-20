#include "TowerMenu.h"

TowerMenu::TowerMenu()
{

    //Button testTower = Button(15, 15, al_load_bitmap("greenTower.png"));
    //for (int i = 0; i < GridHeight; i++)
    //{
    //    for (int j = 0; j < GridWidth; j++)
    //    {
    //        //grid[i][j] = Button(13+(j*(135/GridWidth)), 13+(i*(135/GridWidth)), 135/GridWidth,al_load_bitmap("greenTower.png"));
    //    }
    //    towerList.push_back(Button(13+(0*(135/GridWidth)), 13+(i*(135/GridWidth)), 135/GridWidth,al_load_bitmap("greenTower.png"),"blank"));
    //}
	towerList.push_back(Button(13 + (.5 * (135 / GridWidth)), 13 + (0 * (135 / GridWidth)), 135 / GridWidth, al_load_bitmap("wall.png"), "wall"));
	towerList.push_back(Button(13 + (.5 * (135 / GridWidth)), 13 + (1 * (135 / GridWidth)), 135 / GridWidth, al_load_bitmap("greenTower.png"), "green"));
	towerList.push_back(Button(13 + (.5 * (135 / GridWidth)), 13 + (2 * (135 / GridWidth)), 135 / GridWidth, al_load_bitmap("TowerOrange.png"), "orange"));
	towerList.push_back(Button(13+(.5*(135/GridWidth)), 13+(3*(135/GridWidth)), 135/GridWidth,al_load_bitmap("Tower01.png"), "Dale"));
    disable();
}

void TowerMenu::draw(ALLEGRO_MOUSE_STATE mouse, std::string *title, std::string *desc, int money)
{
    hover = "";
    al_draw_rounded_rectangle(10, 10, 150, ScreenHeight-200, 0, 0, al_color_name("white"), 5);
    /*for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            if(grid[i][j].draw(mouse)==2){
                hover = grid[i][j].GetTowerTitle();
            }
        }
    }*/
    for(std::vector<Button>::iterator it = towerList.begin(); it != towerList.end(); ++it){
        if(it->draw(mouse)==2){
            hover = it->GetTowerTitle();
        }
    }
	if (hover == "green")
	{
		*title = "Standard Tower";
		*desc = "The cheapest tower in the game. $100";
		cost = 100;
	}
	else if (hover == "orange")
	{
		*title = "Laser Tower";
		*desc = "The second best tower in the game $250";
		cost = 250;
	}
	else if (hover == "Dale")
	{
		*title = "Super Tower";
		*desc = "The best tower in the game. $500";
		cost = 500;
	}
	else if (hover == "wall")
	{
		*title = "wall";
		*desc = "a wall to make your maze out of. $5";
		cost = 5;
	}
}

void TowerMenu::disable(){
    for(std::vector<Button>::iterator it = towerList.begin(); it != towerList.end(); ++it){
        it->SetEnabled(false);
        //std::cout << "disabled button" << std::endl;
    }
    enabled= false;
}
void TowerMenu::enable(){
    for(std::vector<Button>::iterator it = towerList.begin(); it != towerList.end(); ++it){
        it->SetEnabled(true);
        //std::cout << "enabled button" << std::endl;
    }
    enabled = true;
}

bool TowerMenu::click(){
    if (enabled)
    {
		if (hover != "")
		{
			std::cout << hover << " clicked" << std::endl;
			return true;
		}
    }
    else
    {
        return false;
    }
}
