#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED
#include "Color.h"
#include "sdlglutils.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

class Cube {
public:
	double x;
	double y;
	double z;
	double h;
	double l;
	double xmap;
	double ymap;
	double zmap;

	GLuint topTexture;
	int text;

	//Temporaire pour mieux visualiser les cubes(couleur du cube)
	Color* color;

	Cube(double x, double y, double z, double h, double l, double xmap,
			double ymap, double zmap, Color* color, GLuint topTexture) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->h = h;
		this->l = l;
		this->xmap = xmap;
		this->ymap = ymap;
		this->zmap = zmap;
		this->color = color;
		this->topTexture = topTexture;

		text = loadTexture("textures/ice0123.jpg");

		char tampon[UCHAR_MAX];

			if (getcwd (tampon, UCHAR_MAX) == NULL) {

			}

			puts (tampon);
	}

	~Cube();

	//Utiliser la fontion glScale() pour agrandir réduire le cube
	void draw() {
		glPushMatrix();
		glTranslated(this->x, this->y, this->z);

		glColor3ub(this->color->getRed(), this->color->getGreen(), this->color->getBlue());

		glBindTexture(GL_TEXTURE_2D, text);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 1);
		glVertex3d(0, 0, 0);
		glTexCoord2d(1, 1);
		glVertex3d(1, 0, 0);
		glTexCoord2d(1, 0);
		glVertex3d(1, 1, 0);
		glTexCoord2d(0, 0);
		glVertex3d(0, 1, 0);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 1);
		glVertex3d(0, 0, 0);
		glTexCoord2d(1, 1);
		glVertex3d(1, 0, 0);
		glTexCoord2d(1, 0);
		glVertex3d(1, 0, 1);
		glTexCoord2d(0, 0);
		glVertex3d(0, 0, 1);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 1);
		glVertex3d(1, 0, 0);
		glTexCoord2d(1, 1);
		glVertex3d(1, 1, 0);
		glTexCoord2d(1, 0);
		glVertex3d(1, 0, 1);
		glTexCoord2d(0, 0);
		glVertex3d(1, 0, 1);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 1);
		glVertex3d(1, 1, 0);
		glTexCoord2d(1, 1);
		glVertex3d(0, 1, 0);
		glTexCoord2d(1, 0);
		glVertex3d(0, 1, 1);
		glTexCoord2d(0, 0);
		glVertex3d(1, 1, 1);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 1);
		glVertex3d(0, 0, 0);
		glTexCoord2d(1, 1);
		glVertex3d(0, 1, 0);
		glTexCoord2d(1, 0);
		glVertex3d(0, 1, 1);
		glTexCoord2d(0, 0);
		glVertex3d(0, 0, 1);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 1);
		glVertex3d(0, 0, 1);
		glTexCoord2d(1, 1);
		glVertex3d(1, 0, 1);
		glTexCoord2d(1, 0);
		glVertex3d(1, 1, 1);
		glTexCoord2d(0, 0);
		glVertex3d(0, 1, 1);
		glEnd();

		glPopMatrix();
	}

	double getX() {
		return this->x;
	}

	double getY() {
		return this->y;
	}

	double getZ() {
		return this->z;
	}

	double getXMap() {
		return this->xmap;
	}

	double getYMap() {
		return this->ymap;
	}

	double getZMap() {
		return this->zmap;
	}
};

#endif // CUBE_H_INCLUDED
