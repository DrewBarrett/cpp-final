#include "DescriptionBox.h"

DescriptionBox::DescriptionBox()
{
    //ctor
}

void DescriptionBox::Draw(std::string title, std::string description){
	ALLEGRO_COLOR color = al_color_name("white");
	if (title == "Game Over") {
		color = al_color_name("red");
	}
    al_draw_rounded_rectangle(10, ScreenHeight - 190, ScreenWidth - 10, ScreenHeight - 10, 7, 7, al_color_name("white"), 5);
    //std::cout << title << " " << description << std::endl;
    al_draw_text(font, color, 20, ScreenHeight - 190, ALLEGRO_ALIGN_LEFT, title.c_str());
    al_draw_text(font, al_color_name("white"), 20, ScreenHeight - 160, ALLEGRO_ALIGN_LEFT, description.c_str());
}
