#include "GridSquare.h"

GridSquare::GridSquare()
{
    x = 0;
    y = 0;
    sideLength = 32;
    highlighted = false;
}

GridSquare::GridSquare(int xPos, int yPos, int side)
{
    x = xPos;
    y = yPos;
    sideLength = side;
    color = al_color_name("white");
    highlighted = false;
}

bool GridSquare::draw(ALLEGRO_MOUSE_STATE state)
{
    if(state.x > x && state.x < x + sideLength && state.y > y && state.y < y + sideLength){
        color = al_color_name("cyan");
        highlighted = true;
    }else{
        color = al_color_name("white");
        highlighted = false;
    }
    if(clicked == true){
        if(occupied == false){
            color = al_color_name("green");
        }
    }
    al_draw_rectangle(x, y, x+sideLength, y+sideLength, color, 1);
    return highlighted;
}
