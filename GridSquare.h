#ifndef GRIDSQUARE_H
#define GRIDSQUARE_H
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include <allegro5/allegro_color.h>
#include "Tower.h"
#include <iostream>
class GridSquare
{
    public:
        /** Default constructor */
        GridSquare();
        GridSquare(int, int, int, int, ALLEGRO_BITMAP*, int, int, std::vector<Enemy> *, ALLEGRO_SAMPLE*);
        /** Access x
         * \return The current value of x
         */
		int GetGScore() { return gScore; }
		void SetGScore(int val) { gScore = val; }
		int GetFScore() { return fScore; }
		void SetFScore(int val) { fScore = val; }
        int Getx() { return x; }
        /** Set x
         * \param val New value to set
         */
        void Setx(int val) { x = val; }
        /** Access y
         * \return The current value of y
         */
        int Gety() { return y; }
        /** Set y
         * \param val New value to set
         */
		void Sety(int val) { y = val; }
		int GetGridX() { return gridX; }
		int GetGridY() { return gridY; }
        /** Access sideLength
         * \return The current value of sideLength
         */
        int GetsideLength() { return sideLength; }
        /** Set sideLength
         * \param val New value to set
         */
        void SetsideLength(int val) { sideLength = val; }
        /** Access occupied
         * \return The current value of occupied
         */
        int Getoccupied() { return occupied; }
        /** Set occupied
         * \param val New value to set
         */
        void Setoccupied(int val);
        /** Access color
         * \return The current value of color
         */
        ALLEGRO_COLOR Getcolor() { return color; }
        /** Set color
         * \param val New value to set
         */
        void Setcolor(ALLEGRO_COLOR val) { color = val; }
        /** Access highlighted
         * \return The current value of highlighted
         */
        bool Gethighlighted() { return highlighted; }
        /** Set highlighted
         * \param val New value to set
         */
        void Sethighlighted(bool val) { highlighted = val; }
        bool GetClicked() { return clicked; }
        /** Set highlighted
         * \param val New value to set
         */
        void SetClicked(bool val) { clicked = val; }
		//void SetParent(GridSquare *val) { parent = val; }
		void SetParentX(int val) { parentX = val; }
		void SetParentY(int val) { parentY = val; }
		int GetParentX() { return parentX; }
		int GetParentY() { return parentY; }
		bool IsParentNull() { return parentX == NULL; }
		bool IsPath() { return onPath; }
		void SetOnPath(bool val) { onPath = val; }
		//GridSquare* GetParent() { return  parent; }
        std::string GetName(){return name;}
        std::string GetDescription() {return description;}
        bool draw(ALLEGRO_MOUSE_STATE);
    protected:
    private:
        int x; //!< Member variable "x"
        int y; //!< Member variable "y"
		int gridX = -1;
		int gridY = -1;
		int gScore;
		int fScore;
        double sideLength; //!< Member variable "sideLength"
        int occupied = 0; //!< Member variable "occupied"
        ALLEGRO_COLOR color; //!< Member variable "color"
		ALLEGRO_SAMPLE *shootsound;
        bool highlighted; //!< Member variable "highlighted"
		bool onPath = false;
        bool clicked = false;
        std::string name = "Grass";
        std::string description = "There is nothing on this tile.";
        ALLEGRO_BITMAP *bg;
		//GridSquare *parent = NULL;
		int parentX = NULL;
		int parentY = NULL;
		Tower tower;
		std::vector<Enemy>* enemies;
};

#endif // GRIDSQUARE_H
