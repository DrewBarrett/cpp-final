#include "TowerMenu.h"

TowerMenu::TowerMenu()
{

    //Button testTower = Button(15, 15, al_load_bitmap("greenTower.png"));
    for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            //grid[i][j] = Button(13+(j*(135/GridWidth)), 13+(i*(135/GridWidth)), 135/GridWidth,al_load_bitmap("greenTower.png"));
        }
        towerList.push_back(Button(13+(0*(135/GridWidth)), 13+(i*(135/GridWidth)), 135/GridWidth,al_load_bitmap("greenTower.png"),"blank"));
    }
    towerList.push_back(Button(13+(0*(135/GridWidth)), 13+(5*(135/GridWidth)), 135/GridWidth,al_load_bitmap("Tower01.png"), "Dale"));
}

void TowerMenu::draw(ALLEGRO_MOUSE_STATE mouse)
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
}

void TowerMenu::disable(){
    for(std::vector<Button>::iterator it = towerList.begin(); it != towerList.end(); ++it){
        it->SetEnabled(false);
        std::cout << "disabled button" << std::endl;
    }
}
void TowerMenu::enable(){
    for(std::vector<Button>::iterator it = towerList.begin(); it != towerList.end(); ++it){
        it->SetEnabled(true);
        std::cout << "enabled button" << std::endl;
    }
}

bool TowerMenu::click(){
    if (hover == "Dale"){
        std::cout << "dale clicked" << std::endl;
    }else{
        std::cout << "no tower clicked" << std::endl;
        return false;
    }
    return true;
}
