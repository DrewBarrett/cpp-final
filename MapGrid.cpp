#include "MapGrid.h"

MapGrid::MapGrid()
{
    for (int i = 0; i < GridHeight; i++)
    {
        for (int j = 0; j < GridWidth; j++)
        {
            grid[i][j] = GridSquare(j*SideLength + ScreenWidth/2 - (SideLength*GridWidth/2), i*SideLength + 10, SideLength);
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
    if(hover != NULL){

        hover->draw(mouse);
    }
}
