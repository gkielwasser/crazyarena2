#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED
#include "Cube.h"

class Obstacle : public Cube {
		public:
			Obstacle();
			Obstacle(const Obstacle &);
			Obstacle(int x, int y, int z, double xmap, double ymap, double zmap,int h, int l, Color* c, GLuint t[5]) : Cube(x, y, z, xmap,ymap,zmap, h, l, c, t) {};
			~Obstacle();
};

#endif // OBSTACLE_H_INCLUDED
