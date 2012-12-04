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
	Color* grey;
	GLuint floorTextures[5];
	GLuint ObstacleTextures[5];

	CubeFactory() {
		//Chargement des couleurss
		this->blue = new Color(255, 255, 255);
		this->blue2 = new Color(51, 204, 255);
		this->grey = new Color(51, 51, 51);

		//Chargement des textures
		GLuint lightFloor, darkFloor;
		lightFloor = loadTexture("textures/ice01.jpg");
		darkFloor = loadTexture("textures/ice01.jpg");

		//Sol
		this->floorTextures[0] = lightFloor;
		this->floorTextures[1] = darkFloor;
		this->floorTextures[2] = darkFloor;
		this->floorTextures[3] = darkFloor;
		this->floorTextures[4] = darkFloor;
		this->floorTextures[5] = darkFloor;

		//Obstacle
		/*
		 this->ObstacleTextures[0];
		 this->ObstacleTextures[1];
		 this->ObstacleTextures[2];
		 this->ObstacleTextures[3];
		 this->ObstacleTextures[4];
		 this->ObstacleTextures[5];
		 */
	}

	CubeFactory(const CubeFactory &);
	~CubeFactory();

	Cube* createCube(double type, double x, double y, double z, double h, double l, double xmap,
			double ymap, double zmap) {
		Cube* cube;

		if (type == 0) {
			cube = this->createFloor(x, y, z, h, l, xmap, ymap, zmap, this->blue,
					this->floorTextures);
		} else {
			cube = this->createObstacle(x, y, z, h, l, xmap, ymap, zmap, this->blue,
					this->ObstacleTextures);
		}

		return cube;
	}

private:
	Floor* createFloor(double x, double y, double z, double h, double l, double xmap, double ymap,
			double zmap, Color* color, GLuint textures[5]) {
		Floor* floor = new Floor(x, y, z, h, l, xmap, ymap, zmap, color, textures);

		return floor;
	}

	Obstacle* createObstacle(double x, double y, double z, double h, double l, double xmap,
			double ymap, double zmap, Color* color, GLuint textures[5]) {
		Obstacle* obstacle = new Obstacle(x, y, z, h, l, xmap, ymap, zmap, color, textures);

		return obstacle;
	}
};

#endif // CUBEFACTORY_H_INCLUDED
