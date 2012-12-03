#ifndef Floor_H_INCLUDED
#define Floor_H_INCLUDED
#include "Cube.h"

class Floor : public Cube {
		public:
			   Floor();
			   Floor(const Floor &);

			   Floor(int x, int y, int z, int h, int l, double xmap, double ymap, double zmap,Color* c) : Cube(x, y, z, xmap, ymap, zmap, h, l, c) {};

	           ~Floor();
};

#endif // FLOOR_H_INCLUDED
