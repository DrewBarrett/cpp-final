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
		std::vector<double> pathx;
		std::vector<double> pathy;
		std::vector<Enemy> *enemies;
		int money = 150;
		int health = 15;
};

#endif // GUI_H
