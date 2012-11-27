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
};

#endif // Map_H_INCLUDED
