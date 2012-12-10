#ifndef PLATEBUILDER_H_INCLUDED
#define PLATEBUILDER_H_INCLUDED
#include "Cube.h"
#include "CubeFactory.h"
#include "Plate.h"
#include <vector>
#include <iostream>

using namespace std;

class PlateBuilder {
public:
	bool contentObstacle;
	int obstaclesNumber;


	PlateBuilder() {
		//Random pour savoir s'il va y avoir un obstacle sur la plaque
		if(randomInt(0,0)){
			this->contentObstacle = true;

			//Random du nombre d'obstacles
			this->obstaclesNumber = randomInt(0,2);
		}
		else{
			this->contentObstacle = false;
			this->obstaclesNumber = 0;
		}

	}

	PlateBuilder(const PlateBuilder &);
	~PlateBuilder();

	Plate* createPlate(float x, float y, float z) {
		CubeFactory* cf = new CubeFactory();

		//Un vecteur par ligne
		vector<Cube*> cubes;

		Plate* plate = new Plate(x, y, z);

		cubes.push_back(cf->createCube(0, 0, 0, 0, 1, 1, x, y, z,plate));
		cubes.push_back(cf->createCube(0, 1, 0, 0, 1, 1, x + 1, y, z,plate));
		cubes.push_back(cf->createCube(0, 2, 0, 0, 1, 1, x + 2, y, z,plate));
		cubes.push_back(cf->createCube(0, 3, 0, 0, 1, 1, x + 3, y, z,plate));

		cubes.push_back(cf->createCube(0, 0, 0, 1, 1, 1, x, y, z + 1,plate));
		cubes.push_back(cf->createCube(0, 1, 0, 1, 1, 1, x + 1, y, z + 1,plate));
		cubes.push_back(cf->createCube(0, 2, 0, 1, 1, 1, x + 2, y, z + 1,plate));
		cubes.push_back(cf->createCube(0, 3, 0, 1, 1, 1, x + 3, y, z + 1,plate));

		cubes.push_back(cf->createCube(0, 0, 0, 2, 1, 1, x, y, z + 2,plate));
		cubes.push_back(cf->createCube(0, 1, 0, 2, 1, 1, x + 1, y, z + 2,plate));
		cubes.push_back(cf->createCube(0, 2, 0, 2, 1, 1, x + 2, y, z + 2,plate));
		cubes.push_back(cf->createCube(0, 3, 0, 2, 1, 1, x + 3, y, z + 2,plate));

		cubes.push_back(cf->createCube(0, 0, 0, 3, 1, 1, x, y, z + 3,plate));
		cubes.push_back(cf->createCube(0, 1, 0, 3, 1, 1, x + 1, y, z + 3,plate));
		cubes.push_back(cf->createCube(0, 2, 0, 3, 1, 1, x + 2, y, z + 3,plate));
		cubes.push_back(cf->createCube(0, 3, 0, 3, 1, 1, x + 3, y, z + 3,plate));

		//Ajout des obstacles (niveau 1 et 2)
		if(this->contentObstacle){
			for(int i = 0; i < this->obstaclesNumber;i++){
				//Random obstacle de leurs positions
				int randX = randomInt(0,3);
				int randZ = randomInt(0,3);
				cubes.push_back(cf->createCube(1, randX, 1, randZ, 1, 1, x + randX, y + 1, z + randZ,plate));
			}
		}



		plate->setCubes(cubes);

		return plate;
	}

	int randomInt(int a, int b){
	    return (a + (rand() % (b-a+1)));
	}

};

#endif // PLATEBUILDER_H_INCLUDED
