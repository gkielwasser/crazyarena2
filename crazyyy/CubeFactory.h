#ifndef CUBEFACTORY_H_INCLUDED
#define CUBEFACTORY_H_INCLUDED
#include "Cube.h"
#include "Floor.h"
#include "Obstacle.h"

class CubeFactory {
public:
	GLuint topTexture;
	Color* blue;
	Color* blue2;

	CubeFactory() {
		this->topTexture = loadTexture("textures/ice01.jpg");
		this->blue = new Color(255, 255, 255);
		this->blue2 = new Color(51, 204, 255);
	}

	CubeFactory(const CubeFactory &);
	~CubeFactory();

	Cube* createCube(double type, double x, double y, double z, double h, double l, double xmap,
			double ymap, double zmap, Color* color, GLuint topTexture) {

		Cube* cube;

		if (type == 0) {
			cube = this->createFloor(x, y, z, h, l, xmap, ymap, zmap, this->blue, this->topTexture);
		} else {
			cube = this->createObstacle(x, y, z, h, l, xmap, ymap, zmap, this->blue, this->topTexture);
		}

		return cube;
	}


private:
	Floor* createFloor(double x, double y, double z,  double h, double l, double xmap,
			double ymap, double zmap, Color* color, GLuint topTexture) {
		Floor* floor = new Floor(x, y, z, h, l, xmap, ymap, zmap, color, topTexture);

		return floor;
	}

	Obstacle* createObstacle(double x, double y, double z, double h, double l, double xmap,
			double ymap, double zmap,Color* color, GLuint topTexture) {
		Obstacle* obstacle = new Obstacle(x, y, z, h, l, xmap, ymap, zmap,
				color, topTexture);

		return obstacle;
	};
};

#endif // CUBEFACTORY_H_INCLUDED
