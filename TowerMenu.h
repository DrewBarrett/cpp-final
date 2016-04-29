#ifndef TOWERMENU_H
#define TOWERMENU_H
#define ScreenWidth 1024
#define ScreenHeight 768
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include <allegro5/allegro_color.h>
#include "Button.h"
#define GridWidth 2
#define GridHeight 5
class TowerMenu
{
    public:
        /** Default constructor */
        TowerMenu();
        void draw(ALLEGRO_MOUSE_STATE);
        /** Access towers[10]
         * \return The current value of towers[10]
         */
/*         tower Gettowers[10]() { return towers[10]; }
 *
 *         void Settowers[10](tower val) { towers[10] = val; }
 */
    protected:
    private:
        //Button testTower = Button(50, 15, al_load_bitmap("greenTower.png"));
        //tower towers[10]; //!< Member variable "towers[10]"
        Button grid[GridHeight][GridWidth];
};

#endif // TOWERMENU_H
