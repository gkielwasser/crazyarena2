#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED
#include "sdlglutils.h"
#include "Color.h"

class Cube {
    public :
	   double x;
	   double y;
	   double z;
	   double h;
	   double l;

	   GLuint text1;
	   GLuint text2;

	   //Temporaire pour mieux visualiser les cubes(couleur du cube)
	   Color* color;

	   Cube(double x, double y, double z, double h, double l, Color* color) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->h = h;
			this->l = l;
			this->color = color;
			//this->text1 = loadTexture("textures/crate1.jpg");
			//this->text2 = loadTexture("textures/crate2.jpg");
	   }

	   ~Cube();

	   //Utiliser la fontion glScale() pour agrandir réduire le cube
	   void draw() {
		    glPushMatrix();

			glColor3ub(this->color->getRed(), this->color->getGreen(), this->color->getBlue());
			glTranslated(this->x,this->y,this->z);
			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glTexCoord2d(0, 1); glVertex3d(0,0,0);
				  glTexCoord2d(1, 1); glVertex3d(1,0,0);
				  glTexCoord2d(1, 0); glVertex3d(1,1,0);
				  glTexCoord2d(0, 0); glVertex3d(0,1,0);
			glEnd();

			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glTexCoord2d(0, 1); glVertex3d(0,0,0);
				  glTexCoord2d(1, 1); glVertex3d(1,0,0);
				  glTexCoord2d(1, 0); glVertex3d(1,0,1);
				  glTexCoord2d(0, 0); glVertex3d(0,0,1);
			glEnd();

			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glTexCoord2d(0, 1); glVertex3d(1,0,0);
				  glTexCoord2d(1, 1); glVertex3d(1,1,0);
				  glTexCoord2d(1, 0); glVertex3d(1, 0, 1);
				  glTexCoord2d(0, 0); glVertex3d(1,0,1);
			glEnd();

			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glTexCoord2d(0, 1); glVertex3d(1,1,0);
				  glTexCoord2d(1, 1); glVertex3d(0,1,0);
				  glTexCoord2d(1, 0); glVertex3d(0,1,1);
				  glTexCoord2d(0, 0); glVertex3d(1,1,1);
			glEnd();

			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glTexCoord2d(0, 1); glVertex3d(0,0,0);
				  glTexCoord2d(1, 1); glVertex3d(0,1,0);
				  glTexCoord2d(1, 0); glVertex3d(0,1,1);
				  glTexCoord2d(0, 0); glVertex3d(0,0,1);
			glEnd();

			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glTexCoord2d(0, 1); glVertex3d(0,0,1);
				  glTexCoord2d(1, 1); glVertex3d(1,0,1);
				  glTexCoord2d(1, 0); glVertex3d(1,1,1);
				  glTexCoord2d(0, 0); glVertex3d(0,1,1);
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
};

#endif // CUBE_H_INCLUDED
