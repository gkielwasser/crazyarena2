#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include "sdlglutils.h"
#include "Color.h"
#include "Position.h"

using namespace std;

class Character {
public:
	double x;
	double y;
	double z;
	double h;
	double l;
	double speed;
	Uint32 jumpStart_time;
	Uint32 lastJump_time;
	bool isJumping;
	bool isDown;
	double rotAngle;

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
		this->isJumping = false;
		this->isDown = true;
		this->lastJump_time = NULL;
		this->rotAngle = 0;
		//this->text1 = loadTexture("textures/crate1.jpg");
		//this->text2 = loadTexture("textures/crate2.jpg");

		this->speed = 1;
	}

	~Character();

	void draw() {
		glPushMatrix();

		glColor3ub(this->color->getRed(), this->color->getGreen(), this->color->getBlue());
		glTranslated(this->x, this->y, this->z);
		//glRotated(rotAngle,0,1,0);

		//glBindTexture(GL_TEXTURE_2D, this->text1);
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

		//glBindTexture(GL_TEXTURE_2D, this->text1);
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

		//glBindTexture(GL_TEXTURE_2D, this->text1);
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

		//glBindTexture(GL_TEXTURE_2D, this->text1);
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

		//glBindTexture(GL_TEXTURE_2D, this->text1);
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

		//glBindTexture(GL_TEXTURE_2D, this->text1);
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

	Position* frontPosition() {
		Position* position = new Position(this->x + speed, this->y - speed, this->z);
		return position;
	}

	void front() {
		this->x += speed;
	}

	Position* backPosition() {
		Position* position = new Position(this->x - speed, this->y - speed, this->z);
		return position;
	}

	void back() {
		this->x -= speed;
	}

	Position* rightPosition() {
		this->rotAngle = -90;
		Position* position = new Position(this->x, this->y - speed, this->z + speed);
		return position;
	}

	void right() {
		this->z += speed;
	}

	Position* leftPosition() {
		this->rotAngle = 90;
		Position* position = new Position(this->x, this->y - speed, this->z - speed);
		return position;
	}

	void left() {
		this->z -= speed;
	}

	Position* upPosition() {
		Position* position = new Position(this->x, this->y + speed, this->z);
		return position;
	}

	void up() {
		//Test le niveau du perso
		if (this->y < 2 && !this->isJumping) {
			//Début du saut
			this->jumpStart_time = SDL_GetTicks();
			this->isJumping = true;
			this->isDown = false;
			this->y += speed;
		}
	}

	Position* downPosition() {
		Position* position = new Position(this->x, this->y - speed, this->z);
		return position;
	}

	void down() {
		this->lastJump_time = SDL_GetTicks();
		if (this->y > 1)
			this->y -= speed;
		this->isJumping = false;
	}

	double getX() {
		return this->x;
	}

	void setX(double x) {
		this->x = x;
	}

	double getY() {
		return this->y;
	}

	void setY(double y) {
		this->y = y;
	}

	double getZ() {
		return this->z;
	}

	void setZ(double z) {
		this->z = z;
	}

	Uint32 getJumpStartTime() {
		return this->jumpStart_time;
	}
	void setJumpStartTime(Uint32 time) {
		this->jumpStart_time = time;
	}
};

#endif // CHARACTER_H_INCLUDED
