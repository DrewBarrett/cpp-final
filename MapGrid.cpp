#include "MapGrid.h"

MapGrid::MapGrid()
{
    srand (time(NULL));
	ALLEGRO_BITMAP *bitmap = al_load_bitmap("grass.png");
    for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            grid[i][j] = GridSquare(j*SideLength + ScreenWidth/2 - (SideLength*GridWidth/2), i*SideLength + 10, SideLength, 0, bitmap);
            if((i == GridHeight - 1)){
                grid[i][j].Setoccupied(2);
            }
        }
    }
    ALLEGRO_BITMAP *arrow = al_load_bitmap("arrow.png");
    int random = rand()%GridWidth;
    grid[0][random] = GridSquare(random*SideLength + ScreenWidth/2 - (SideLength*GridWidth/2), 0*SideLength + 10, SideLength, 1, arrow);
    start = &grid[0][random];
    std::cout << random << " start set" << std::endl;
    random = rand() % GridWidth;
    finish = &grid[GridHeight][random];
    std::cout << random << " finish set" << std::endl;
}

void MapGrid::draw(ALLEGRO_MOUSE_STATE mouse, std::string *title, std::string *description)
{
    hover = NULL;
    for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            if (grid[i][j].draw(mouse))
            {
                hover = &grid[i][j];
            }
        }
    }
    if(clicked != NULL){
        clicked->draw(mouse);
        *title = clicked->GetName();
        *description = clicked->GetDescription();
    }
    if(hover != NULL){
        hover->draw(mouse);
    }
}

void MapGrid::SetClicked()
{
    if (clicked != NULL)
    {
        clicked->SetClicked(false);
    }
    clicked = hover;
}
