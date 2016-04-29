#include "MapGrid.h"

MapGrid::MapGrid()
{
	ALLEGRO_BITMAP *bitmap = al_load_bitmap("grass.png");
    for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            grid[i][j] = GridSquare(j*SideLength + ScreenWidth/2 - (SideLength*GridWidth/2), i*SideLength + 10, SideLength, bitmap);
        }
    }
}

void MapGrid::draw(ALLEGRO_MOUSE_STATE mouse)
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
