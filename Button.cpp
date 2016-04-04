#include "Button.h"

Button::Button(int x1, int y1, std::string text1)
{
	x = x1;
	y = y1;
	text = text1;
	height = 35;
	width = text.size() * 20;
	font = al_load_font("comic.ttf", 20, 0);
	color = al_color_name("white");
}

void Button::draw(ALLEGRO_MOUSE_STATE state)
{
	color = al_color_name("white");
	int thickness = checkMouse(state);
	al_draw_text(font, al_color_name("white"), x, y, ALLEGRO_ALIGN_CENTRE, text.c_str());
	al_draw_rectangle(x - width, y, x + width, y + height, color, thickness);
}

int Button::checkMouse(ALLEGRO_MOUSE_STATE state)
{
	if ((state.y >= y&& state.y <= y + height)
		&& (state.x >= x - width && state.x <= x + width)) {
		color = al_color_name("cyan");
		return 2;
	}
	return 1;
}
