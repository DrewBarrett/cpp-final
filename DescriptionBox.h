#ifndef DESCRIPTIONBOX_H
#define DESCRIPTIONBOX_H
#define ScreenWidth 1024
#define ScreenHeight 768
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include <allegro5/allegro_color.h>
#include <iostream>

class DescriptionBox
{
    public:
        /** Default constructor */
        DescriptionBox();
        void Draw(std::string, std::string);
    protected:
    private:
};

#endif // DESCRIPTIONBOX_H
