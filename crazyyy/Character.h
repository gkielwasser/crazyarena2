#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include "sdlglutils.h"
#include "Color.h"
#include "Position.h"
#include "math.h"
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
	bool isJumping; // est en train de sauter
	bool isOnTheGround; // est sur le sol
	bool isTurningLeft;
	bool isTurningRight;
	bool isDown;
	float rotAngle;
	float jumpSpeed;
	double yGoal;
	double yStart;


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
		this->speed = 1;
		this->isOnTheGround = true;
		this->jumpSpeed = 0.25;
	}

	~Character();

	void draw() {

		glPushMatrix();

		glColor3ub(this->color->getRed(), this->color->getGreen(), this->color->getBlue());
		glTranslated(this->x, this->y, this->z);
		glTranslatef( 0.5, 0.5, 0.5 );
		glRotated(rotAngle, 0, -1, 0);
		glTranslatef( -0.5, -0.5, -0.5 );

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

		glPopMatrix();
	}

	Position* frontPosition() {
		Position* position = new Position(this->x + speed, this->y - speed, this->z);
		return position;
	}

	Position* backPosition() {
		Position* position = new Position(this->x - speed, this->y - speed, this->z);
		return position;
	}

	Position* rightPosition() {
		Position* position = new Position(this->x, this->y - speed, this->z + speed);
		return position;
	}

	Position* leftPosition() {
		Position* position = new Position(this->x, this->y - speed, this->z - speed);
		return position;
	}

	/*
	 * Obstacle
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
		this->x += round(float(cos(this->rotAngle / 180 * 3.141592654f)));
		this->z += round(float(sin(this->rotAngle / 180 * 3.141592654f)));
	}

	void back() {
		this->x -= round(float(cos(this->rotAngle / 180 * 3.141592654f)));
		this->z -= round(float(sin(this->rotAngle / 180 * 3.141592654f)));
	}

	void right() {
		this->x -= round(float(sin(this->rotAngle / 180 * 3.141592654f)));
		this->z += round(float(cos(this->rotAngle / 180 * 3.141592654f)));
	}

	void left() {
		this->x += round(float(sin(this->rotAngle / 180 * 3.141592654f)));
		this->z -= round(float(cos(this->rotAngle / 180 * 3.141592654f)));
	}

	void up() {
		//Début du saut
		//this->jumpStart_time = SDL_GetTicks();
		this->isJumping = true;
		this->isOnTheGround = false;
		this->yGoal = this->y + 1;
		this->yStart = this->y;
		cout<<"yGoal:"<<yGoal<<"  yStart:"<<yStart<<endl;
		//this->isDown = false;
		//this->y += speed;
		//this->y += speed;
	}

	void down() {
		//this->lastJump_time = SDL_GetTicks();
		//this->isJumping = false;
		this->y -= speed;
	}

	void smoothUp(){
		//S'il n'est pas arrivé au Y final
		if(this->y < this->yGoal) this->y += this->jumpSpeed;
		//Sinon descendre
		else{
			this->isJumping = false;
			smoothDown();
		}
	}

	void smoothDown(){
		//S'il n'est pas encore au sol
		if(this->y > this->yStart)	this->y -= this->jumpSpeed;
		//S'il est arrivé au sol
		else if(this->y == this->yStart){
			this->isOnTheGround = true;
		}
	}

	void rotateRight() {
		this->rotAngle = this->rotAngle + 90;
	}
	void rotateLeft() {
		this->rotAngle = this->rotAngle - 90;
	}
	void rotateBack() {
		this->rotAngle = this->rotAngle + 180;
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
