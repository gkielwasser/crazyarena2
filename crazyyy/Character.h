#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include "sdlglutils.h"
#include "Color.h"
#include "Position.h"
#include "math.h"
using namespace std;

class Character {
public:
	float x;
	float y;
	float z;
	float h;
	float l;
	float speed;
	Uint32 jumpStart_time;
	Uint32 lastJump_time;
	bool isJumping; // est en train de sauter
	bool isOnTheGround; // est sur le sol
	bool isTurningLeft;
	bool isTurningRight;
	bool isTurningBack;
	bool isDown;
	float rotAngle;
	float rotAngleGoal;
	float jumpSpeed;
	float yGoal;
	float yStart;

	//Temporaire pour mieux visualiser les cubes(couleur du cube)
	Color* color;

	Character(float x, float y, float z, float h, float l, Color* color) {
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
		this->rotAngleGoal = 0;
		this->speed = 0.05;
		this->isOnTheGround = true;
		this->jumpSpeed = 0.05;
		this->isTurningLeft = false;
		this->isTurningRight = false;
		this->isTurningBack = false;
	}

	~Character();

	void draw() {

		glPushMatrix();

		if (this->speed == 0)
			glColor3ub(this->color->getRed(), this->color->getGreen(), this->color->getBlue());

		glTranslated(this->x, this->y, this->z);
		glTranslatef(0.5, 0.5, 0.5);
		glRotated(rotAngle, 0, -1, 0);
		glTranslatef(-0.5, -0.5, -0.5);

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
		glVertex3d(1, 1, 1);
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

		if (this->speed == 0)
			glColor3ub(255, 255, 255);

		glPopMatrix();
	}

	/*
	 Position* frontPosition() {
	 Position* position = new Position(this->x + speed, this->y - speed, this->z);
	 return position;
	 }
	 */
	Position* frontPosition() {
		Position* position = new Position(this->x + speed, this->y - 1, this->z);
		return position;
	}

	Position* backPosition() {
		Position* position = new Position(this->x - speed, this->y - 1, this->z);
		return position;
	}

	Position* rightPosition() {
		Position* position = new Position(this->x, this->y - 1, this->z + speed);
		return position;
	}

	Position* leftPosition() {
		Position* position = new Position(this->x, this->y - 1, this->z - speed);
		return position;
	}

	/*
	 * Obstacle
	 */
	/*
	 Position* frontObstaclePosition() {
	 Position* position = new Position(this->x + speed, this->y, this->z);
	 return position;
	 }
	 */
	Position* frontObstaclePosition() {
		Position* position = new Position(this->x + speed, this->y, this->z);
		return position;
	}

	Position* leftObstaclePosition() {
		Position* position = new Position(this->x, this->y, this->z - speed);
		return position;
	}

	Position* rightObstaclePosition() {
		Position* position = new Position(this->x, this->y, this->z + speed);
		return position;
	}

	/*
	 * Sous le personnage
	 */
	Position* frontDownPosition() {
		Position* position = new Position(this->x, this->y - speed, this->z);
		return position;
	}

	void front() {
		//cout << "angle:" << this->rotAngle << "angle/180:" << (rotAngle / 180) << "tot:" << (cos(
		//this->rotAngle / 180 * M_PI)) << endl;
		this->x += float(cos(this->rotAngle / 180 * M_PI)) * speed;
		this->z += float(sin(this->rotAngle / 180 * M_PI)) * speed;
	}

	void back() {
		this->x -= round(float(cos(this->rotAngle / 180 * M_PI)));
		this->z -= round(float(sin(this->rotAngle / 180 * M_PI)));
	}

	void right() {
		this->x -= round(float(sin(this->rotAngle / 180 * M_PI)));
		this->z += round(float(cos(this->rotAngle / 180 * M_PI)));
	}

	void left() {
		this->x += round(float(sin(this->rotAngle / 180 * M_PI)));
		this->z -= round(float(cos(this->rotAngle / 180 * M_PI)));
	}

	void up() {
		//Début du saut
		this->isJumping = true;
		this->isOnTheGround = false;
		this->yGoal = this->y + 2;
		this->yStart = this->y;
		//cout << "yGoal:" << yGoal << "  yStart:" << yStart << endl;
	}

	void down() {
		//this->lastJump_time = SDL_GetTicks();
		//this->isJumping = false;
		this->y -= speed;
	}

	void smoothUp() {
		//S'il n'est pas arrivé au Y final
		if (this->y < this->yGoal)
			this->y += this->jumpSpeed;
		//Sinon descendre
		else {
			this->isJumping = false;
		}
	}

	void smoothDown() {
		//S'il n'est pas encore au sol
		if (this->y > this->yStart)
			this->y -= this->jumpSpeed;
		//S'il est arrivé au sol
		else if (this->y == this->yStart) {
			this->isOnTheGround = true;
		}
	}

	void smoothRight() {
		//cout << "angle right:" << rotAngle << endl;
		if (this->rotAngle != this->rotAngleGoal) {
			this->isTurningRight = true;
			this->rotAngle =int(this->rotAngle + 9)%360;
		} else {
			this->isTurningRight = false;
		}
	}

	void smoothLeft() {
		//cout << "angle left:" << rotAngle << endl;
		if (this->rotAngle != this->rotAngleGoal) {
			this->isTurningLeft = true;
			this->rotAngle =int(this->rotAngle - 9)%360;
		} else {
			this->isTurningLeft = false;
		}
	}

	void smoothBack() {
		//cout << "angle back:" << rotAngle << endl;
		if (this->rotAngle != this->rotAngleGoal) {
			this->isTurningBack = true;
			this->rotAngle = int(this->rotAngle + 9)%360;
		} else {
			this->isTurningBack = false;
		}
	}

	void rotateRight() {
		this->isTurningRight = true;
		this->rotAngleGoal = int(this->rotAngle + 90)%360;
	}
	void rotateLeft() {
		this->isTurningLeft = true;
		this->rotAngleGoal = int(this->rotAngle - 90)%360;
	}
	void rotateBack() {
		this->isTurningBack = true;
		this->rotAngleGoal = int(this->rotAngle + 180)%360;
	}

	float getX() {
		return this->x;
	}

	void setX(float x) {
		this->x = x;
	}

	float getY() {
		return this->y;
	}

	void setY(float y) {
		this->y = y;
	}

	float getZ() {
		return this->z;
	}

	void setZ(float z) {
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
