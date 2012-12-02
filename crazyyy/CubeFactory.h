#ifndef CUBEFACTORY_H_INCLUDED
#define CUBEFACTORY_H_INCLUDED
#include "Cube.h"
#include "Floor.h"
#include "Obstacle.h"

class CubeFactory {
public:
	CubeFactory() {
	}
	;
	CubeFactory(const CubeFactory &);
	~CubeFactory();

	Cube* createCube(double type, double x, double y, double z, double h, double l, double xmap,
			double ymap, double zmap, Color* color) {
		Cube* cube;

		if (type == 1) {
			cube = this->createFloor(x, y, z, h, l, xmap, ymap, zmap, color);
		} else {
			cube = this->createObstacle(x, y, z, h, l, xmap, ymap, zmap, color);
		}

		return cube;
	}
	;

private:
	Floor* createFloor(double x, double y, double z,  double h, double l, double xmap,
			double ymap, double zmap,Color* color) {
		Floor* floor = new Floor(x, y, z, h, l, xmap, ymap, zmap, color);

		return floor;
	}
	;

	Obstacle* createObstacle(double x, double y, double z, double h, double l, double xmap,
			double ymap, double zmap,Color* color) {
		Obstacle* obstacle = new Obstacle(x, y, z, h, l, xmap, ymap, zmap,
				color);

		return obstacle;
	}
	;
};

#endif // CUBEFACTORY_H_INCLUDED
