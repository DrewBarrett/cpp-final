#include "GridSquare.h"

GridSquare::GridSquare()
{
    x = 0;
    y = 0;
    sideLength = 32;
    highlighted = false;
    bg = NULL;
}

GridSquare::GridSquare(int xPos, int yPos, int side, int type, ALLEGRO_BITMAP *bitmap, int gx, int gy)
{
    x = xPos;
    y = yPos;
	gridX = gx;
	gridY = gy;
    sideLength = side;
    color = al_color_name("white");
    highlighted = false;
	bg = bitmap;
	//Occupied 0 is Grass, Occupied 1 is the start tile, Occupied 2 is one of the end walls and Occupied 3 is a Dale Tower
	Setoccupied(type);
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
        if(occupied == 0){
            color = al_color_name("green");
        }else{
            color = al_color_name("red");
        }
    }
    if (bg != NULL){
        if (occupied > 1)
        {
            al_draw_filled_rectangle(x,y,x+sideLength,y+sideLength,al_color_name("gray"));
        }
        if (occupied != 2)
        {
            al_draw_scaled_bitmap(bg, 0, 0, al_get_bitmap_width(bg), al_get_bitmap_width(bg), x, y, sideLength, sideLength, 0);
        }
    }
    al_draw_rectangle(x, y, x+sideLength, y+sideLength, color, 1);
    return highlighted;
}

void GridSquare::Setoccupied(int val)
{
    occupied = val;
    switch(occupied)
    {
		case 4:
			name = "End";
			description = "This is where the enemies are trying to go";
			break;
        case 3:
            name = "Gun Tower";
            description = "A standard tower that shoots the enemies.";
            bg = al_load_bitmap("tower01.png");
			//TODO: dont reload the bitmap every time!
            break;
        case 2:
            name = "Wall";
            description = "This the the wall you are trying to defend from the Mongolized Weapon Kiwis.";
            break;
        case 1:
            name = "Start";
            description = "This is where the enemies will spawn in from.";
            break;
        default:
            name = "Grass";
            description = "There is nothing on this tile.";
			bg = al_load_bitmap("grass.png");
            break;
    }
}
