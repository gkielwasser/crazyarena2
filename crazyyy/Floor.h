#ifndef Floor_H_INCLUDED
#define Floor_H_INCLUDED
#include "Cube.h"

class Floor : public Cube {
		public:
			   Floor();
			   Floor(const Floor &);

				Floor(int x, int y, int z, double xmap, double ymap, double zmap,int h, int l, Color* c, GLuint t) : Cube(x, y, z, xmap,ymap,zmap, h, l, c,t) {};

	           ~Floor();
};

#endif // FLOOR_H_INCLUDED
