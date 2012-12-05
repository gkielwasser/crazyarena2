#ifndef PLATE_H_INCLUDED
#define PLATE_H_INCLUDED
#include <vector>
#include "Cube.h"

using namespace std;

class Plate {
protected:
	vector<Cube*> cubes;
	double x;
	double y;
	double z;

public:
	Plate(vector<Cube*> cubes) {
		this->cubes = cubes;
	}


	//Constructeur d'une Plate
	Plate(double x, double y, double z, vector<Cube*> cubes) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->cubes = cubes;

		this->draw();
	}

	~Plate();

	void draw() {
		glPushMatrix();
		glTranslated(this->x, this->y, this->z);
		// Pour chaque cube
		for (unsigned int i = 0; i < this->cubes.size(); i++) {
			this->cubes[i]->draw();
		}
		glPopMatrix();
	}

	void addObstacle(double x, double y, double z,Color* color){
		//Obstacle obs = new Obstacle(4,4,4,4,4,4,1,1,color,GLuint* textures);
	}

	vector<Cube*> getCubes() {
		return this->cubes;
	}
	double getX() {
		return x;
	}

	double getY() {
		return y;
	}

	double getZ() {
		return z;
	}
};

#endif // PLATE_H_INCLUDED
