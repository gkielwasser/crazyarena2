#ifndef PLATE_H_INCLUDED
#define PLATE_H_INCLUDED
#include <vector>
#include "Cube.h"

using namespace std;

class Plate {
	protected:
		vector<Cube*> cubes;

    public :
	   Plate(vector<Cube*> cubes) {
		   this->cubes = cubes;
	   };

	   ~Plate();

	   void draw() {
		   // Pour chaque cube
			for (unsigned int i = 0; i < this->cubes.size(); i++) {
				this->cubes[i]->draw();
			}
	   };

	   vector<Cube*> getCubes() {
		   return this->cubes;
	   }
};
#endif // PLATE_H_INCLUDED
