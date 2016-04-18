#ifndef MAPGRID_H
#define MAPGRID_H
#include "GridSquare.h"

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
