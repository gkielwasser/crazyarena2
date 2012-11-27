#ifndef Floor_H_INCLUDED
#define Floor_H_INCLUDED
#include "Cube.h"

class Floor : public Cube {
		public:
			   Floor();
			   Floor(const Floor &);

			   Floor(int x, int y, int z, int h, int l) : Cube(x, y, z, h, l) {};

	           ~Floor();
};

#endif // FLOOR_H_INCLUDED
