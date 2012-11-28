#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED
#include "Cube.h"

class Obstacle : public Cube {
		public:
			Obstacle();
			Obstacle(const Obstacle &);
			Obstacle(int x, int y, int z, int h, int l, Color* c) : Cube(x, y, z, h, l, c) {};
			~Obstacle();
};

#endif // OBSTACLE_H_INCLUDED
