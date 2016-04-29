#include "Button.h"

Button::Button()
{

}

Button::Button(int x1, int y1, std::string text1)
{
	x = x1;
	y = y1;
	text = text1;
	height = 35;
	width = text.size() * 20;
	// = al_load_font("comic.ttf", 20, 0);
	color = al_color_name("white");
	img = NULL;
}

Button::Button(int x1, int y1, int w1, ALLEGRO_BITMAP *sprite)
{
    x = x1;
    y = y1;
    text = "";
    height = w1;
    width = w1;
    img = sprite;
    //font = al_load_font("comic.ttf", 20, 0);
}

void Button::draw(ALLEGRO_MOUSE_STATE state)
{
    int thickness = 1;
    if(enabled){
        color = al_color_name("white");
        thickness = checkMouse(state);
    }
	else {
        thickness = 1;
        color = al_color_name("gray");
	}
	al_draw_text(font, al_color_name("white"), x, y, ALLEGRO_ALIGN_CENTRE, text.c_str());
	if (img != NULL)
    {
        al_draw_filled_rectangle(x, y, x+ width, y + height, al_color_name("gray"));
        al_draw_scaled_bitmap(img, 0, 0, 1000, 1000, x, y, width, height, 0);
    }
    al_draw_rectangle(x, y, x + width, y + height, color, thickness);
}

int Button::checkMouse(ALLEGRO_MOUSE_STATE state)
{
	if ((state.y >= y&& state.y <= y + height)
		&& (state.x >= x && state.x <= x + width)) {
		color = al_color_name("cyan");
		return 2;
	}
	return 1;
}
