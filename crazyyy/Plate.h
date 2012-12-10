#ifndef PLATE_H_INCLUDED
#define PLATE_H_INCLUDED
#include <vector>
#include "Cube.h"

using namespace std;

class Plate {
protected:
	vector<Cube*> cubes;
	int x;
	int y;
	int z;

public:
	Plate(vector<Cube*> cubes) {
		this->cubes = cubes;
	}


	//Constructeur d'une Plate
	Plate(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
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

	vector<Cube*> getCubes() {
		return this->cubes;
	}
	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	int getZ() {
		return z;
	}

	void setCubes(vector<Cube*> cubes){
		this->cubes = cubes;
	}
};

#endif // PLATE_H_INCLUDED
