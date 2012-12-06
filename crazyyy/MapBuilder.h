#ifndef MAPBUILDER_H_INCLUDED
#define MAPBUILDER_H_INCLUDED
#include "Map.h"
#include "Cube.h"
#include "CubeFactory.h"
#include "PlateBuilder.h"
#include "Plate.h"
#include <vector>

using namespace std;

class MapBuilder {
public:
	MapBuilder() {
	}
	;
	MapBuilder(const MapBuilder &);
	~MapBuilder();

	Map* createMap() {
		PlateBuilder* p = new PlateBuilder();

		vector<Plate*> plates;

		//Line 1
		plates.push_back(p->createPlate(0, 0, 0));
		plates.push_back(p->createPlate(4, 0, 0));
		plates.push_back(p->createPlate(8, 0, 0));
		plates.push_back(p->createPlate(12, 0, 0));
		plates.push_back(p->createPlate(16, 0, 0));
		plates.push_back(p->createPlate(20, 0, 0));

		//Ligne 2
		plates.push_back(p->createPlate(0, 0, 4));
		plates.push_back(p->createPlate(20, 0, 4));

		//Ligne 3
		plates.push_back(p->createPlate(0, 0, 8));
		plates.push_back(p->createPlate(4, 0, 8));
		plates.push_back(p->createPlate(8, 0, 8));
		plates.push_back(p->createPlate(12, 0, 8));
		plates.push_back(p->createPlate(16, 0, 8));
		plates.push_back(p->createPlate(20, 0, 8));

		//Ligne 3 LVL3

		plates.push_back(p->createPlate(0, 2, 8));
		plates.push_back(p->createPlate(4, 2, 8));
		plates.push_back(p->createPlate(8, 2, 8));
		plates.push_back(p->createPlate(12, 2, 8));
		plates.push_back(p->createPlate(16, 2, 8));
		plates.push_back(p->createPlate(20, 2, 8));
		

		//Ligne 4
		plates.push_back(p->createPlate(0, 0, 12));
		plates.push_back(p->createPlate(16, 0, 12));

		//Ligne 5
		plates.push_back(p->createPlate(0, 0, 16));
		plates.push_back(p->createPlate(8, 0, 16));
		plates.push_back(p->createPlate(12, 0, 16));
		plates.push_back(p->createPlate(16, 0, 16));
		plates.push_back(p->createPlate(20, 0, 16));

		//Ligne 6
		plates.push_back(p->createPlate(0, 0, 20));
		plates.push_back(p->createPlate(4, 0, 20));
		plates.push_back(p->createPlate(8, 0, 20));

		//Ligne 6 LVL3
		
		plates.push_back(p->createPlate(0, 2, 20));
		plates.push_back(p->createPlate(4, 2, 20));
		plates.push_back(p->createPlate(8, 2, 20));
		

		//Niveau 0
		plates.push_back(p->createPlate(0, -4, 12));
		plates.push_back(p->createPlate(4, -4, 12));
		plates.push_back(p->createPlate(8, -4, 12));
		plates.push_back(p->createPlate(12, -4, 12));
		plates.push_back(p->createPlate(16, -4, 12));
		plates.push_back(p->createPlate(20, -4, 12));

		//Création d'une map avec son vecteur de plate
		Map* map = new Map(plates);

		return map;
	}
};

#endif // MAPBUILDER_H_INCLUDED
