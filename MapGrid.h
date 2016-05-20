#ifndef MAPGRID_H
#define MAPGRID_H
#include "GridSquare.h"
#include <vector>
#include <cmath>
#include <sstream>
#define ScreenWidth 1024
#define ScreenHeight 768
#define GridWidth 10
#define GridHeight 8
#define SideLength 70
#include <iostream>

class MapGrid
{
    public:
        /** Default constructor */
		MapGrid();
        MapGrid(std::vector<Enemy> *);
        void draw(ALLEGRO_MOUSE_STATE, std::string*, std::string*);
        GridSquare* GetHover(){return hover;}
        GridSquare* GetClicked(){return clicked;}
        void SetClicked();
        bool IsClicked(){return clicked != NULL;}
		bool Pathfind();
		void ReconstructPath();
		void DrawPath();
		void GetPath(std::vector<int> *,std::vector<int> *);
		int EstimateCostToFinish(int x, int y);
		//void setEnemies(std::vector<Enemy> *);
    protected:
    private:
		ALLEGRO_SAMPLE *shootsound = al_load_sample("shotsound.wav");
        GridSquare *hover;
        GridSquare *clicked = NULL;
        GridSquare *start = NULL;
        GridSquare *finish = NULL;
        GridSquare grid[GridHeight][GridWidth];
		std::vector<GridSquare*> path;
		std::vector<int> pathx;
		std::vector<int> pathy;
		std::vector<Enemy>* enemies;
		int startx = -1;
		int finishx = -1;
};

#endif // MAPGRID_H
