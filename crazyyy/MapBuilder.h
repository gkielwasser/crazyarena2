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
			MapBuilder(){};
			MapBuilder(const MapBuilder &);
			~MapBuilder();

			Map* createMap() {
				//CubeFactory* cf = new CubeFactory();

				//Création de 2 couleurs(temporaire)
				Color* blue = new Color(255, 255, 255);
				//Color* blue2 = new Color(51, 204, 255);

				PlateBuilder* p = new PlateBuilder();

				vector<Plate*> plates;

				//Line 1
				plates.push_back(p->createPlate(0,0,0,blue));
				plates.push_back(p->createPlate(4,0,0,blue));
				plates.push_back(p->createPlate(8,0,0,blue));
				plates.push_back(p->createPlate(12,0,0,blue));
				plates.push_back(p->createPlate(16,0,0,blue));
				plates.push_back(p->createPlate(20,0,0,blue));

				//Ligne 2
				plates.push_back(p->createPlate(0,0,4,blue));
				plates.push_back(p->createPlate(20,0,4,blue));

				//Ligne 3
				plates.push_back(p->createPlate(0,0,8,blue));
				plates.push_back(p->createPlate(4,0,8,blue));
				plates.push_back(p->createPlate(8,0,8,blue));
				plates.push_back(p->createPlate(12,0,8,blue));
				plates.push_back(p->createPlate(16,0,8,blue));
				plates.push_back(p->createPlate(20,0,8,blue));

				//Ligne 3 LVL3
				/*
				plates.push_back(p->createPlate(0,3,8,blue2));
				plates.push_back(p->createPlate(4,3,8,blue2));
				plates.push_back(p->createPlate(8,3,8,blue2));
				plates.push_back(p->createPlate(12,3,8,blue2));
				plates.push_back(p->createPlate(16,3,8,blue2));
				plates.push_back(p->createPlate(20,3,8,blue2));
				*/
				//Ligne 4
				plates.push_back(p->createPlate(0,0,12,blue));
				plates.push_back(p->createPlate(16,0,12,blue));

				//Ligne 5
				plates.push_back(p->createPlate(0,0,16,blue));
				plates.push_back(p->createPlate(8,0,16,blue));
				plates.push_back(p->createPlate(12,0,16,blue));
				plates.push_back(p->createPlate(16,0,16,blue));
				plates.push_back(p->createPlate(20,0,16,blue));

				//Ligne 6
				plates.push_back(p->createPlate(0,0,20,blue));
				plates.push_back(p->createPlate(4,0,20,blue));
				plates.push_back(p->createPlate(8,0,20,blue));

				//Ligne 6 LVL3
				/*
				plates.push_back(p->createPlate(0,4,20,blue2));
				plates.push_back(p->createPlate(4,4,20,blue2));
				plates.push_back(p->createPlate(8,4,20,blue2));
				*/
				//Création d'une map avec son vecteur de plate
				Map* map = new Map(plates);

 				return map;
			};
			/*
			Plate* createPlaque(){
				//Plate* plate = new Plate(cubes);
				return plate;
			}
			*/
};

#endif // MAPBUILDER_H_INCLUDED
