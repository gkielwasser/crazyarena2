#ifndef PLATEBUILDER_H_INCLUDED
#define PLATEBUILDER_H_INCLUDED
#include "Cube.h"
#include "CubeFactory.h"
#include "Plate.h"
#include <vector>

using namespace std;

class PlateBuilder {
public:
	PlateBuilder() {
	}

	PlateBuilder(const PlateBuilder &);
	~PlateBuilder();

	Plate* createPlate(double x, double y, double z) {
		CubeFactory* cf = new CubeFactory();

		//Un vecteur par ligne
		vector<Cube*> cubes;

		cubes.push_back(cf->createCube(0, 0, 0, 0, 1, 1, x, y, z));
		cubes.push_back(cf->createCube(0, 1, 0, 0, 1, 1, x + 1, y, z));
		cubes.push_back(cf->createCube(0, 2, 0, 0, 1, 1, x + 2, y, z));
		cubes.push_back(cf->createCube(0, 3, 0, 0, 1, 1, x + 3, y, z));

		cubes.push_back(cf->createCube(0, 0, 0, 1, 1, 1, x, y, z + 1));
		cubes.push_back(cf->createCube(0, 1, 0, 1, 1, 1, x + 1, y, z + 1));
		cubes.push_back(cf->createCube(0, 2, 0, 1, 1, 1, x + 2, y, z + 1));
		cubes.push_back(cf->createCube(0, 3, 0, 1, 1, 1, x + 3, y, z + 1));

		cubes.push_back(cf->createCube(0, 0, 0, 2, 1, 1, x, y, z + 2));
		cubes.push_back(cf->createCube(0, 1, 0, 2, 1, 1, x + 1, y, z + 2));
		cubes.push_back(cf->createCube(0, 2, 0, 2, 1, 1, x + 2, y, z + 2));
		cubes.push_back(cf->createCube(0, 3, 0, 2, 1, 1, x + 3, y, z + 2));

		cubes.push_back(cf->createCube(0, 0, 0, 3, 1, 1, x, y, z + 3));
		cubes.push_back(cf->createCube(0, 1, 0, 3, 1, 1, x + 1, y, z + 3));
		cubes.push_back(cf->createCube(0, 2, 0, 3, 1, 1, x + 2, y, z + 3));
		cubes.push_back(cf->createCube(0, 3, 0, 3, 1, 1, x + 3, y, z + 3));

		Plate* plate = new Plate(x, y, z, cubes);

		return plate;
	}

};

#endif // PLATEBUILDER_H_INCLUDED
