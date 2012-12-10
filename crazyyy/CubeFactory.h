#ifndef CUBEFACTORY_H_INCLUDED
#define CUBEFACTORY_H_INCLUDED
#include "Cube.h"
#include "Floor.h"
#include "Obstacle.h"
#include "sdlglutils.h"

class CubeFactory {
public:
	GLuint topTexture;
	Color* blue;
	Color* blue2;
	Color* grey;
	Color* red;
	GLuint floorTextures[5];
	GLuint ObstacleTextures[5];
//Test
	CubeFactory() {
		//Chargement des couleurss
		this->blue = new Color(255, 255, 255);
		this->blue2 = new Color(51, 204, 255);
		this->grey = new Color(51, 51, 51);
		this->red = new Color(255,255,0);

		//Chargement des textures
		GLuint lightFloor, darkFloor;
		lightFloor = loadTexture("textures/ice128.jpg");
		darkFloor = loadTexture("textures/watermark2.jpg");

		//Sol
		this->floorTextures[0] = lightFloor;
		this->floorTextures[1] = lightFloor;
		this->floorTextures[2] = lightFloor;
		this->floorTextures[3] = lightFloor;
		this->floorTextures[4] = lightFloor;
		this->floorTextures[5] = lightFloor;

		//Obstacle

		 this->ObstacleTextures[0]=darkFloor;
		 this->ObstacleTextures[1]=darkFloor;
		 this->ObstacleTextures[2]=darkFloor;
		 this->ObstacleTextures[3]=darkFloor;
		 this->ObstacleTextures[4]=darkFloor;
		 this->ObstacleTextures[5]=darkFloor;

	}

	CubeFactory(const CubeFactory &);
	~CubeFactory();

	Cube* createCube(int type, int x, int y, int z, float h, float l, float xmap,
			float ymap, float zmap,Plate* plate) {
		Cube* cube;

		if (type == 0) {
			cube = this->createFloor(x, y, z, h, l, xmap, ymap, zmap, this->blue,
					this->floorTextures,plate);
		} else {
			cube = this->createObstacle(x, y, z, h, l, xmap, ymap, zmap, this->red,
					this->ObstacleTextures,plate);
		}

		return cube;
	}

private:
	Floor* createFloor(int x, int y, int z, float h, float l, float xmap, float ymap,
			float zmap, Color* color, GLuint textures[5],Plate* plate) {
		Floor* floor = new Floor(x, y, z, h, l, xmap, ymap, zmap, color, textures,plate);

		return floor;
	}

	Obstacle* createObstacle(int x, int y, int z, float h, float l, float xmap,
			float ymap, float zmap, Color* color, GLuint textures[5],Plate* plate) {
		Obstacle* obstacle = new Obstacle(x, y, z, h, l, xmap, ymap, zmap, color, textures,plate);

		return obstacle;
	}
};

#endif // CUBEFACTORY_H_INCLUDED
