#include "bonus.h"
#include <gl.h>
#include <glu.h>
#include <math.h>
#include <glut.h>
using namespace std;

/**
 * Couleur:
 * 1 = orange
 * 2 = vert
 */

Bonus::Bonus(int x, int y, int a, int speed, int type){
	this->x = x;
	this->y = y;
	this->a = a;
	this->speed = speed;
	this->type = type;
}

void Bonus::Draw() {
     this->Position();

    // Sauvegarde du rep�re
    glPushMatrix();

    // Changement de rep�re
    glTranslated(x, y, 0);
    glRotated(a, 0, 0, 1);

    // On dessine ici ce qu'on veut
    glBegin(GL_QUADS);
    	if(this->type == 1)
    		glColor3ub(63,114,255);
    	else
    		glColor3ub(255,76,180);
        glVertex2d(-8, -8);
        glVertex2d(-8, 8);
        glVertex2d(8, 8);
        glVertex2d(8, -8);
    glEnd();



    // Remise en �tat du rep�re
    glPopMatrix();
}
void Bonus::Position() {
    x += cos(a*M_PI/180)*speed;
    if (x > 1024) {
          x = 0;
    }
    else if (x < 0) {
         x = 1024;
    }

    y += sin(a*M_PI/180)*speed;
    if (y > 768) {
          y = 0;
    }
    else if (y < 0) {
         y = 768;
    }
}
double Bonus::getX() {
       return x;
}

int Bonus::getType(){
return type;
}

double Bonus::getY() {
       return y;
}
double Bonus::getA() {
       return a;
}

Bonus::~Bonus() {
};
