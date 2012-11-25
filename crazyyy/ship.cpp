#include "ship.h"
#include <gl.h>
#include <glu.h>
#include <math.h>

using namespace std;

Ship::Ship(double x, double y, double a, int type) {
     this->x = x;
     this->y = y;
     this->a = a;
     this->type = type;
     
     speed = 0;
     life = 10;
     previousSpeed = speed;
	  shield = false;
	  bonusType = 0;
	  color = 0;
	  this->visible = true;
}

void Ship::Draw() {
     this->Position();
     
    // Sauvegarde du rep�re
    glPushMatrix();

    // Changement de rep�re
    glTranslated(x, y, 0);
    
    if (life > 0 && life <= 3) {
		glColor3ub(255, 0, 0);
	}
	else if (life >= 4 && life <= 6) {
		glColor3ub(255, 130, 0);
	}
	else if (life >= 7) {
		glColor3ub(0, 255, 0);
	}

    for (int i = 0; i < life; i++) {
		glBegin(GL_QUADS);
			glVertex2d(-40 + (i * 10), 40);
			glVertex2d(-35 + (i * 10), 40);
			glVertex2d(-40 + (i * 10), 35);
			glVertex2d(-35 + (i * 10), 35);
		glEnd();
	}

    glRotated(a, 0, 0, 1);
    
    if (bonusType == 0) {
    	glColor3ub(255, 255, 255);
    }
    else if (bonusType == 1) {
    	glColor3ub(63, 114, 255);
    }
    else if (bonusType == 2) {
    	glColor3ub(255,76,180);
    }

    if (type == 1) {
		glBegin(GL_QUADS);
			glVertex2d(-10, -10);
			glVertex2d(-10, 10);
			glVertex2d(10, 10);
			glVertex2d(10, -10);
		glEnd();

		glBegin(GL_TRIANGLES);
			glVertex2d(-8, 0);
			glVertex2d(30, 10);
			glVertex2d(-8, 20);
		glEnd();

		glBegin(GL_TRIANGLES);
			glVertex2d(-8, 0);
			glVertex2d(30, -10);
			glVertex2d(-8, -20);
		glEnd();

		glBegin(GL_TRIANGLES);
			glVertex2d(-5, 0);
			glVertex2d(-15, -10);
			glVertex2d(-15, 10);
		glEnd();
    }
    else {
    	glBegin(GL_QUADS);
			glVertex2d(-10, -10);
			glVertex2d(-10, 10);
			glVertex2d(10, 10);
			glVertex2d(10, -10);
		glEnd();

		glBegin(GL_TRIANGLES);
			glVertex2d(10, -10);
			glVertex2d(10, 10);
			glVertex2d(30, 0);
		glEnd();

		glBegin(GL_TRIANGLES);
			glVertex2d(-10, -5);
			glVertex2d(-10, 5);
			glVertex2d(-20, 0);
		glEnd();

		glBegin(GL_TRIANGLES);
			glVertex2d(-10, -10);
			glVertex2d(10, -10);
			glVertex2d(-30, -30);
		glEnd();

		glBegin(GL_TRIANGLES);
			glVertex2d(10, 10);
			glVertex2d(-10, 10);
			glVertex2d(-30, 30);
		glEnd();
    }

    // Remise en �tat du rep�re
    glPopMatrix();
}

void Ship::Left() {
     a += 5;
}

void Ship::Right() {
     a -= 5;
}

void Ship::Up() {
     if (speed < 100) {
        speed++;
     }
}

void Ship::Down() {
     if (speed > 0) {
        speed--;
     }
}

void Ship::recede() {
	x -= 50;
	y -= 50;
	a -= 50;
	speed -= 50;
}

void Ship::Position() {
    x += cos(a*M_PI/180)*speed/15;
    if (x > 1024) {
          x = 0;
    }
    else if (x < 0) {
         x = 1024;
    }
    
    y += sin(a*M_PI/180)*speed/15;
    if (y > 768) {
          y = 0;
    }
    else if (y < 0) {
         y = 768;
    }
}

void Ship::increaseLife() {
	life++;
}

void Ship::decreaseLife() {
	life--;
}

double Ship::getX() {
       return x;
}

double Ship::getY() {
       return y;
}

double Ship::getA() {
       return a;
}

double Ship::getSpeed() {
       return speed;
}

int Ship::getLife() {
       return life;
}

void Ship::ChangeColor(int color){
	this->color = color ;
}

void Ship::Boost(){
	previousSpeed = speed;
	speed += 100;
	ChangeColor(1);
	bonusType = 1;
}

void Ship::StopBoost(){
	speed = previousSpeed;
	ChangeColor(0);
	bonusType = 0;
}

void Ship::Shield(){
	shield = true;
	ChangeColor(2);
	bonusType = 2;
}

void Ship::StopShield(){
	shield = false;
	ChangeColor(0);
	bonusType = 0;
}

int Ship::getBonusType(){
	return bonusType;
}
