#include "GridSquare.h"

GridSquare::GridSquare()
{
    x = 0;
    y = 0;
    sideLength = 32;
    highlighted = false;
    bg = NULL;
}

GridSquare::GridSquare(int xPos, int yPos, int side, ALLEGRO_BITMAP *bitmap)
{
    x = xPos;
    y = yPos;
    sideLength = side;
    color = al_color_name("white");
    highlighted = false;
	bg = bitmap;
	occupied = false;
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
    if (bg != NULL){
        al_draw_scaled_bitmap(bg, 0, 0, 1000, 1000, x, y, sideLength, sideLength, 0);
    }
    al_draw_rectangle(x, y, x+sideLength, y+sideLength, color, 1);
    return highlighted;
}
