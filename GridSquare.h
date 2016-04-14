#ifndef GRIDSQUARE_H
#define GRIDSQUARE_H
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include <allegro5/allegro_color.h>
class GridSquare
{
    public:
        /** Default constructor */
        GridSquare(int, int, int);
        /** Access x
         * \return The current value of x
         */
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
        bool Getoccupied() { return occupied; }
        /** Set occupied
         * \param val New value to set
         */
        void Setoccupied(bool val) { occupied = val; }
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
    protected:
    private:
        int x; //!< Member variable "x"
        int y; //!< Member variable "y"
        int sideLength; //!< Member variable "sideLength"
        bool occupied; //!< Member variable "occupied"
        ALLEGRO_COLOR color; //!< Member variable "color"
        bool highlighted; //!< Member variable "highlighted"
};

#endif // GRIDSQUARE_H
