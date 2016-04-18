#ifndef MAPGRID_H
#define MAPGRID_H
#include "GridSquare.h"
#define ScreenWidth 1024
#define ScreenHeight 768
#define GridWidth 10
#define GridHeight 8
#define SideLength 70

class MapGrid
{
    public:
        /** Default constructor */
        MapGrid();
        void draw(ALLEGRO_MOUSE_STATE);

    protected:
    private:
        GridSquare *hover;
        GridSquare grid[GridHeight][GridWidth];
};

#endif // MAPGRID_H
