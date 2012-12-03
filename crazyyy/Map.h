#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "Plate.h"
#include <vector>

using namespace std;

class Map {
	protected:
		vector<Plate*> plates;

	public:
		   Map();
		   Map(const Map &);

		   Map(vector<Plate*> plates) {
			   this->plates = plates;
		   }

		   ~Map();

		   void draw() {
			   // Pour chaque plaque
				for (unsigned int i = 0; i < plates.size(); i++) {
					plates[i]->draw();
				}
		   }

		   Cube* getCube(int x, int y, int z) {
			   Cube* cube = 0;

			   for (unsigned int i = 0; i < plates.size(); i++) {
				   vector<Cube*> cubes = this->plates[i]->getCubes();

				   for (unsigned int j = 0; j < cubes.size(); j++) {
					   if (cubes[j]->getXMap() == x && cubes[j]->getYMap() == y && cubes[j]->getZMap() == z) {
						   cube = cubes[j];
					   }
				   }
			   }

			   return cube;
		   };
};

#endif // Map_H_INCLUDED
