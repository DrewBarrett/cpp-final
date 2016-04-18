#include "MapGrid.h"

MapGrid::MapGrid()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = GridSquare(i*48, j*48, 48);
        }
    }
}

void MapGrid::draw(ALLEGRO_MOUSE_STATE mouse)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j].draw(mouse))
            {
                hover = &grid[i][j];
            }
        }
    }
    hover->draw(mouse);
}
