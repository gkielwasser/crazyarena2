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
				Color* green = new Color(51, 204, 0);

				//Création d'un vecteur de 16 cubes
				vector<Cube*> cubes;
				cubes.push_back(cf->createCube(0, 0, 0, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 0, 0, 1, 1, 1, green));
				cubes.push_back(cf->createCube(0, 0, 0, 2, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 0, 0, 3, 1, 1, green));

				cubes.push_back(cf->createCube(0, 1, 0, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 1, 0, 1, 1, 1, green));
				cubes.push_back(cf->createCube(0, 1, 0, 2, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 1, 0, 3, 1, 1, green));

				cubes.push_back(cf->createCube(0, 2, 0, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 2, 0, 1, 1, 1, green));
				cubes.push_back(cf->createCube(0, 2, 0, 2, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 2, 0, 3, 1, 1, green));

				cubes.push_back(cf->createCube(0, 3, 0, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 3, 0, 1, 1, 1, green));
				cubes.push_back(cf->createCube(0, 3, 0, 2, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 3, 0, 3, 1, 1, green));


				//Création d'une plate avec son vecteur de cubes
				Plate* plate = new Plate(cubes);

				//Création d'un vecteur de plate
				vector<Plate*> plates;
				plates.push_back(plate);

				//Création d'une map avec son vecteur de plate
				Map* map = new Map(plates);

 				return map;
			};
};

#endif // MAPBUILDER_H_INCLUDED
