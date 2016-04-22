#include "DescriptionBox.h"

DescriptionBox::DescriptionBox()
{
    //ctor
}

void DescriptionBox::Draw(){
    al_draw_rounded_rectangle(10, ScreenHeight - 190, ScreenWidth - 10, ScreenHeight - 10, 7, 7, al_color_name("white"), 5);
}
