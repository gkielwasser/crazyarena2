#include "asteroid.h"
#include <gl.h>
#include <glu.h>
#include <math.h>

using namespace std;

Asteroid::Asteroid(int x, int y, int a, int rot, int speed, int height) {
	this->x = x;
	 this->y = y;
	 this->height = height;
	 this->width = height;
	 this->a = a;
	 this->rot = rot;
	 this->speed = speed;
}

void Asteroid::Draw() {
     this->Position();
     
    // Sauvegarde du rep�re
    glPushMatrix();
    
    // Changement de rep�re
    glTranslated(x, y, 0);
    glRotated(a, 0, 0, 1);
    
    // On dessine ici ce qu'on veut
    glBegin(GL_QUADS);
    	glColor3ub(50,50,50);
    	glVertex2d(-height, -width);
    	glVertex2d(-height, width);
    	glVertex2d(height, width);
    	glVertex2d(height, -width);
    glEnd();
    
    // Remise en �tat du rep�re
    glPopMatrix();
}

void Asteroid::Position() {
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

double Asteroid::getX() {
       return x;
}

double Asteroid::getY() {
       return y;
}

double Asteroid::getA() {
       return a;
}

void Asteroid::rotate(int rand){

	if (this->rot != 0)
		a += rand;
}

Asteroid::~Asteroid() {
};
