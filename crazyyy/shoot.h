#ifndef SHOOT_H_INCLUDED
#define SHOOT_H_INCLUDED
#include "ship.h"

class Shoot {
    public :
           double x;
           double y;
           double a;
           double speed;
           Ship* ship;
           Shoot(); // Non impl�ment� donc inutilisable
           Shoot(const Shoot &); // Constructeur de copie, non impl�ment� donc interdit
           Shoot(Ship* ship);
           void Draw();
           void Position();
           double getX();
           double getY();
           double getA();
           Ship* getShip();
           ~Shoot(); // Destructeur
};
#endif // SHOOT_H_INCLUDED
