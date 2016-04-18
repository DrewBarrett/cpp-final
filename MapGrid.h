#ifndef MAPGRID_H
#define MAPGRID_H
#include "GridSquare.h"
#define ScreenWidth 1024
#define ScreenHeight 768

class MapGrid
{
    public:
        /** Default constructor */
        MapGrid();
        void draw(ALLEGRO_MOUSE_STATE);

    protected:
    private:
        GridSquare *hover;
        GridSquare grid[10][10];
};

#endif // MAPGRID_H
