#ifndef GUI_H
#define GUI_H
#include "TowerMenu.h"
#include "MapGrid.h"
#include "DescriptionBox.h"
#include "WavePanel.h"
#include "WaveManager.h"

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
		WavePanel wavepanel;
		WaveManager wavemanager;
		std::vector<int> pathx;
		std::vector<int> pathy;
		std::vector<Enemy> *enemies;
};

#endif // GUI_H
