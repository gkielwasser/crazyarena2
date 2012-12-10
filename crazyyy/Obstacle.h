#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED
#include "Cube.h"
#include "Plate.h"

class Obstacle: public Cube {
public:
	int rotAngle;
	Obstacle();
	Obstacle(const Obstacle &);
	Obstacle(int x, int y, int z, int xmap, int ymap, int zmap, int h, int l, Color* c,
			GLuint t[5], Plate* plate) :
		Cube(x, y, z, xmap, ymap, zmap, h, l, c, t,plate) {
		this->rotAngle = 0;
	}

	~Obstacle();

	int newAngle(){
		this->rotAngle = (this->rotAngle + 10 % 360);
		return this->rotAngle;
	}

	//Utiliser la fontion glScale() pour agrandir réduire le cube
	virtual void draw() {

		glPushMatrix();
		glTranslated(this->x, this->y, this->z);
		//glTranslatef( 0.5, 0.5, 0.5 );
		//glRotated(newAngle(),0,1,0);
		//glTranslatef( -0.5, -0.5, -0.5 );
		//glColor3ub(51, 51, 51);

		glBindTexture(GL_TEXTURE_2D, this->textures[0]);


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


		//glColor3ub(51, 51, 51);
		glBindTexture(GL_TEXTURE_2D, this->textures[1]);
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


		//glColor3ub(51, 51, 51);
		glBindTexture(GL_TEXTURE_2D, this->textures[2]);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 1);
		glVertex3d(1, 0, 0);
		glTexCoord2d(1, 1);
		glVertex3d(1, 1, 0);
		glTexCoord2d(1, 0);
		glVertex3d(1, 1, 1);
		glTexCoord2d(0, 0);
		glVertex3d(1, 0, 1);
		glEnd();


		//glColor3ub(this->color->getRed(), this->color->getGreen(), this->color->getBlue());
		glBindTexture(GL_TEXTURE_2D, this->textures[3]);
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

		//glColor3ub(51, 51, 51);
		glBindTexture(GL_TEXTURE_2D, this->textures[4]);
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

		//glColor3ub(51, 51, 51);
		glBindTexture(GL_TEXTURE_2D, this->textures[5]);
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
};

#endif // OBSTACLE_H_INCLUDED
