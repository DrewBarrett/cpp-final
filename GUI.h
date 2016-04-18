#ifndef GUI_H
#define GUI_H
#include "TowerMenu.h"
#include "MapGrid.h"

class GUI
{
    public:
        /** Default constructor */
        GUI();
        void Draw(ALLEGRO_MOUSE_STATE);
    protected:
    private:
        MapGrid mapgrid;
        TowerMenu towermenu;
};

#endif // GUI_H
