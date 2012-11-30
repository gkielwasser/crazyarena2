#ifndef MAPBUILDER_H_INCLUDED
#define MAPBUILDER_H_INCLUDED
#include "Map.h"
#include "Cube.h"
#include "CubeFactory.h"
#include "Plate.h"
#include <vector>

using namespace std;

class MapBuilder {
		public:
			MapBuilder(){};
			MapBuilder(const MapBuilder &);
			~MapBuilder();

			Map* createMap() {
				CubeFactory* cf = new CubeFactory();

				//Création de 2 couleurs(temporaire)
				Color* blue = new Color(51, 102, 255);
				Color* blue2 = new Color(51, 204, 255);

				// Plaque 1
				vector<Cube*> cubes;
				cubes.push_back(cf->createCube(0, 0, 0, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 0, 1, 0, 1, 1, blue2));
				cubes.push_back(cf->createCube(0, 0, 2, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 0, 3, 0, 1, 1, blue2));

				cubes.push_back(cf->createCube(0, 1, 0, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 1, 1, 0, 1, 1, blue2));
				cubes.push_back(cf->createCube(0, 1, 2, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 1, 3, 0, 1, 1, blue2));

				cubes.push_back(cf->createCube(0, 2, 0, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 2, 1, 0, 1, 1, blue2));
				cubes.push_back(cf->createCube(0, 2, 2, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 2, 3, 0, 1, 1, blue2));

				cubes.push_back(cf->createCube(0, 3, 0, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 3, 1, 0, 1, 1, blue2));
				cubes.push_back(cf->createCube(0, 3, 2, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 3, 3, 0, 1, 1, blue2));

				// Plaque 2
				vector<Cube*> cubes2;
				cubes2.push_back(cf->createCube(0, 4, 0, 0, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 4, 1, 0, 1, 1, blue2));
				cubes2.push_back(cf->createCube(0, 4, 2, 0, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 4, 3, 0, 1, 1, blue2));

				cubes2.push_back(cf->createCube(0, 5, 0, 0, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 5, 1, 0, 1, 1, blue2));
				cubes2.push_back(cf->createCube(0, 5, 2, 0, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 5, 3, 0, 1, 1, blue2));

				cubes2.push_back(cf->createCube(0, 6, 0, 0, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 6, 1, 0, 1, 1, blue2));
				cubes2.push_back(cf->createCube(0, 6, 2, 0, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 6, 3, 0, 1, 1, blue2));

				cubes2.push_back(cf->createCube(0, 7, 0, 0, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 7, 1, 0, 1, 1, blue2));
				cubes2.push_back(cf->createCube(0, 7, 2, 0, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 7, 3, 0, 1, 1, blue2));

				// Plaque 3
				vector<Cube*> cubes3;
				cubes3.push_back(cf->createCube(0, 8, 0, 0, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 8, 1, 0, 1, 1, blue2));
				cubes3.push_back(cf->createCube(0, 8, 2, 0, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 8, 3, 0, 1, 1, blue2));

				cubes3.push_back(cf->createCube(0, 9, 0, 0, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 9, 1, 0, 1, 1, blue2));
				cubes3.push_back(cf->createCube(0, 9, 2, 0, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 9, 3, 0, 1, 1, blue2));

				cubes3.push_back(cf->createCube(0, 10, 0, 0, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 10, 1, 0, 1, 1, blue2));
				cubes3.push_back(cf->createCube(0, 10, 2, 0, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 10, 3, 0, 1, 1, blue2));

				cubes3.push_back(cf->createCube(0, 11, 0, 0, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 11, 1, 0, 1, 1, blue2));
				cubes3.push_back(cf->createCube(0, 11, 2, 0, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 11, 3, 0, 1, 1, blue2));

				// Plaque 7
				vector<Cube*> cubes7;
				cubes7.push_back(cf->createCube(0, 0, 4, 0, 1, 1, blue));
				cubes7.push_back(cf->createCube(0, 0, 5, 0, 1, 1, blue2));
				cubes7.push_back(cf->createCube(0, 0, 6, 0, 1, 1, blue));
				cubes7.push_back(cf->createCube(0, 0, 7, 0, 1, 1, blue2));

				cubes7.push_back(cf->createCube(0, 1, 4, 0, 1, 1, blue));
				cubes7.push_back(cf->createCube(0, 1, 5, 0, 1, 1, blue2));
				cubes7.push_back(cf->createCube(0, 1, 6, 0, 1, 1, blue));
				cubes7.push_back(cf->createCube(0, 1, 7, 0, 1, 1, blue2));

				cubes7.push_back(cf->createCube(0, 2, 4, 0, 1, 1, blue));
				cubes7.push_back(cf->createCube(0, 2, 5, 0, 1, 1, blue2));
				cubes7.push_back(cf->createCube(0, 2, 6, 0, 1, 1, blue));
				cubes7.push_back(cf->createCube(0, 2, 7, 0, 1, 1, blue2));

				cubes7.push_back(cf->createCube(0, 3, 4, 0, 1, 1, blue));
				cubes7.push_back(cf->createCube(0, 3, 5, 0, 1, 1, blue2));
				cubes7.push_back(cf->createCube(0, 3, 6, 0, 1, 1, blue));
				cubes7.push_back(cf->createCube(0, 3, 7, 0, 1, 1, blue2));


				//Création d'une plate avec son vecteur de cubes
				Plate* plate = new Plate(cubes);
				Plate* plate2 = new Plate(cubes2);
				Plate* plate3 = new Plate(cubes3);
				Plate* plate7 = new Plate(cubes7);

				//Création d'un vecteur de plate
				vector<Plate*> plates;

				// Ligne 1
				plates.push_back(plate);
				plates.push_back(plate2);
				plates.push_back(plate3);

				//Ligne 2
				plates.push_back(plate7);

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
