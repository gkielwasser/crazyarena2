#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "Plate.h"
#include <vector>

using namespace std;

class Map {
protected:
	vector<Plate*> plates;
	int far;
	int near;

public:
	Map();
	Map(const Map &);

	Map(vector<Plate*> plates) {
		this->plates = plates;
		this->far = 28;
		this->near = -4;
	}

	~Map();

	void draw(float x, float y, float z) {
		// Pour chaque plaque
		for (unsigned int i = 0; i < plates.size(); i++) {
			if(plates[i]->getX() > int(x - far)  && plates[i]->getX() < int(x + far)  && plates[i]->getZ() >= int(z)+ near  && plates[i]->getZ() < int(z + far) ) plates[i]->draw();
		}
	}

	Cube* getCube(int x, int y, int z) {
		Cube* cube = 0;

		for (unsigned int i = 0; i < plates.size(); i++) {
			vector<Cube*> cubes = this->plates[i]->getCubes();

			for (unsigned int j = 0; j < cubes.size(); j++) {
				if (cubes[j]->getXMap() == x && cubes[j]->getYMap() == y && cubes[j]->getZMap() == z) {
					cube = cubes[j];
				}
			}
		}

		return cube;
	}
	;
	Cube* getCubeCol(int x, int y, int z) {
		Cube* cube = 0;

		for (unsigned int i = 0; i < plates.size(); i++) {
			vector<Cube*> cubes = this->plates[i]->getCubes();

			for (unsigned int j = 0; j < cubes.size(); j++) {
				if (cubes[j]->getXCol() == x && cubes[j]->getYMap() == y && cubes[j]->getZMap() == z) {
					cube = cubes[j];
				}
			}
		}

		return cube;
	}
	;
};

#endif // Map_H_INCLUDED
