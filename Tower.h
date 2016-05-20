#ifndef TOWER_H
#define TOWER_H
#include "Enemy.h"
#include <math.h>

class Tower
{
    public:
        /** Default constructor */
        Tower();
        Tower(std::vector<Enemy> *, int, int);
        /** Access firerate
         * \return The current value of firerate
         */

        void Update();

        int Getfirerate() { return firerate; }
        /** Set firerate
         * \param val New value to set
         */
        void Setfirerate(int val) { firerate = val; }
        /** Access *target
         * \return The current value of *target
         */
        //Enemy Gettarget() { return *target; }
        /** Set *target
         * \param val New value to set
         */
        void Settarget(Enemy *val) { target = val; }
        /** Access rotation
         * \return The current value of rotation
         */
        double Getrotation() { return rotation; }
        /** Set rotation
         * \param val New value to set
         */
        void Setrotation(int val) { rotation = val; }
    protected:
    private:
        int firerate; //!< Member variable "firerate"
        Enemy *target = NULL; //!< Member variable "*target"
        double rotation; //!< Member variable "rotation"
        std::vector<Enemy>* enemies = NULL;
        int x;
        int y;
};

#endif // TOWER_H
