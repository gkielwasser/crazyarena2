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
			MapBuilder();
			MapBuilder(const MapBuilder &);
			~MapBuilder();

			Map* createMap() {
				CubeFactory* cf = new CubeFactory();

				vector<Cube*> cubes;
				cubes.push_back(cf->createCube(1, 0, 0, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 1, 0, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 2, 0, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 3, 0, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 0, 1, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 1, 1, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 2, 1, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 3, 1, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 0, 2, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 1, 2, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 2, 2, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 3, 2, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 0, 3, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 1, 3, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 2, 3, 0, 1, 1));
				cubes.push_back(cf->createCube(1, 3, 3, 0, 1, 1));
				Plate* plate = new Plate(cubes);

				vector<Plate*> plates;
				plates.push_back(plate);

				Map* map = new Map(plates);

 				return map;
			};
};

#endif // MAPBUILDER_H_INCLUDED
