#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include "sdlglutils.h"
#include "Color.h"
#include "Position.h"

using namespace std;

class Character {
    public :
	   double x;
	   double y;
	   double z;
	   double h;
	   double l;
	   double speed;

	   GLuint text1;
	   GLuint text2;

	   //Temporaire pour mieux visualiser les cubes(couleur du cube)
	   Color* color;

	   Character(double x, double y, double z, double h, double l, Color* color) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->h = h;
			this->l = l;
			this->color = color;
			//this->text1 = loadTexture("textures/crate1.jpg");
			//this->text2 = loadTexture("textures/crate2.jpg");

			this->speed = 1;
	   }

	   ~Character();

	   void draw() {
			glColor3ub(this->color->getRed(), this->color->getGreen(), this->color->getBlue());

			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glRotated(0, 0, 0, 0); // On fait une roation de 270° selon l'axe x (valeur, boolean x, boolean y, boolean z)
				  glTexCoord2d(0, 1); glVertex3d(this->x, this->y, this->z);
				  glTexCoord2d(1, 1); glVertex3d(this->x + this->l, this->y, this->z);
				  glTexCoord2d(1, 0); glVertex3d(this->x + this->l, this->y + this->l, this->z);
				  glTexCoord2d(0, 0); glVertex3d(this->x, this->y + this->l, this->z);
			glEnd();

			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glRotated(0, 0, 0, 0); // On fait une roation de 270° selon l'axe x (valeur, boolean x, boolean y, boolean z)
				  glTexCoord2d(0, 1); glVertex3d(this->x, this->y, this->z);
				  glTexCoord2d(1, 1); glVertex3d(this->x + this->l, this->y, this->z);
				  glTexCoord2d(1, 0); glVertex3d(this->x + this->l, this->y, this->z + this->h);
				  glTexCoord2d(0, 0); glVertex3d(this->x, this->y, this->z + this->h);
			glEnd();

			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glRotated(0, 0, 0, 0); // On fait une roation de 270° selon l'axe x (valeur, boolean x, boolean y, boolean z)
				  glTexCoord2d(0, 1); glVertex3d(this->x + this->l, this->y, this->z);
				  glTexCoord2d(1, 1); glVertex3d(this->x + this->l, this->y + this->l, this->z);
				  glTexCoord2d(1, 0); glVertex3d(this->x + this->l, this->y + this->l, this->z + this->h);
				  glTexCoord2d(0, 0); glVertex3d(this->x + this->l, this->y, this->z + this->h);
			glEnd();

			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glRotated(0, 0, 0, 0); // On fait une roation de 270° selon l'axe x (valeur, boolean x, boolean y, boolean z)
				  glTexCoord2d(0, 1); glVertex3d(this->x + this->l, this->y + this->l, this->z);
				  glTexCoord2d(1, 1); glVertex3d(this->x, this->y + this->l, this->z);
				  glTexCoord2d(1, 0); glVertex3d(this->x, this->y + this->l, this->z + this->h);
				  glTexCoord2d(0, 0); glVertex3d(this->x + this->l, this->y + this->l, this->z + this->h);
			glEnd();

			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glRotated(0, 0, 0, 0); // On fait une roation de 270° selon l'axe x (valeur, boolean x, boolean y, boolean z)
				  glTexCoord2d(0, 1); glVertex3d(this->x, this->y,            this->z);
				  glTexCoord2d(1, 1); glVertex3d(this->x, this->y + this->l,  this->z);
				  glTexCoord2d(1, 0); glVertex3d(this->x, this->y + this->l,  this->z + this->h);
				  glTexCoord2d(0, 0); glVertex3d(this->x, this->y,            this->z + this->h);
			glEnd();

			//glBindTexture(GL_TEXTURE_2D, this->text1);
			glBegin(GL_QUADS);
				  glRotated(0, 0, 0, 0); // On fait une roation de 270° selon l'axe x (valeur, boolean x, boolean y, boolean z)
				  glTexCoord2d(0, 1); glVertex3d(this->x, this->y, this->z + this->h);
				  glTexCoord2d(1, 1); glVertex3d(this->x + this->l, this->y, this->z + this->h);
				  glTexCoord2d(1, 0); glVertex3d(this->x + this->l, this->y + this->l, this->z + this->h);
				  glTexCoord2d(0, 0); glVertex3d(this->x, this->y + this->l, this->z + this->h);
			glEnd();
	   }

	   Position* frontPosition() {
		   Position* position = new Position(this->x + speed, this->y - 1, this->z);

		   return position;
	   };

	   void front() {
		   this->x += speed;
	   }

	   Position* leftPosition() {
		   Position* position = new Position(this->x, this->y - 1, this->z + speed);

		   return position;
	   };

	   void left() {
		   this->z += speed;
	   }

	   Position* rightPosition() {
		   Position* position = new Position(this->x, this->y - 1, this->z - speed);

		   return position;
	   };

	   void right() {
		   this->z -= speed;
	   }

	   double getX() {
		   return this->x;
	   }

	   void setX(double x)
	   {
	       this->x = x;
	   }

	   double getY() {
		   return this->y;
	   }

	   void setY(double y)
	   {
	       this->y = y;
	   }

	   double getZ() {
		   return this->z;
	   }

	   void setZ(double z)
	   {
	       this->z = z;
	   }
};

#endif // CHARACTER_H_INCLUDED
