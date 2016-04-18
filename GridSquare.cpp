#include "GridSquare.h"

GridSquare::GridSquare()
{
    x = 0;
    y = 0;
    sideLength = 32;
}

GridSquare::GridSquare(int xPos, int yPos, int side)
{
    x = xPos;
    y = yPos;
    sideLength = side;
    color = al_color_name("white");
}

void GridSquare::draw(ALLEGRO_MOUSE_STATE mouse)
{
    al_draw_rectangle(x, y, x+sideLength, y+sideLength, color, 1);
}
