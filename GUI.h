#ifndef GUI_H
#define GUI_H
#include "TowerMenu.h"
#include "MapGrid.h"
#include "DescriptionBox.h"

class GUI
{
    public:
        /** Default constructor */
        GUI();
        void Draw(ALLEGRO_MOUSE_STATE);
        void MouseClicked();
    protected:
    private:
        MapGrid mapgrid;
        TowerMenu towermenu;
        DescriptionBox descriptionbox;
};

#endif // GUI_H
