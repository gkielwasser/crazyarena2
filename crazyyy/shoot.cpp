#include "shoot.h"
#include <gl.h>
#include <glu.h>
#include <math.h>
#include "ship.h"

using namespace std;

Shoot::Shoot(Ship* ship) {
     this->x = ship->getX();
     this->y = ship->getY();
     this->a = ship->getA();
     this->ship = ship;
     
     speed = 7 + (ship->getSpeed() / 10);
}

void Shoot::Draw() {
     this->Position();
     
    // Sauvegarde du rep�re
    glPushMatrix();
    
    // Changement de rep�re
    glTranslated(x, y, 0);
    glRotated(a, 0, 0, 1);
    
    // On dessine ici ce qu'on veut
    glBegin(GL_QUADS);
        glColor3ub(255,255,0); glVertex2d(-3, -3);
        glColor3ub(255,255,0); glVertex2d(-3, 3);
        glColor3ub(255,255,0); glVertex2d(3, 3);
        glColor3ub(255,255,0); glVertex2d(3, -3);
    glEnd();
    
    // Remise en �tat du rep�re
    glPopMatrix();
}

void Shoot::Position() {
    x += cos(a*M_PI/180)*speed;
    y += sin(a*M_PI/180)*speed;
}

double Shoot::getX() {
       return x;
}

double Shoot::getY() {
       return y;
}

double Shoot::getA() {
       return a;
}

Ship* Shoot::getShip() {
       return ship;
}

Shoot::~Shoot() {
};
