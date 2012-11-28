#ifndef CUBEFACTORY_H_INCLUDED
#define CUBEFACTORY_H_INCLUDED
#include "Cube.h"
#include "Floor.h"
#include "Obstacle.h"

class CubeFactory {
		public:
			CubeFactory(){};
			CubeFactory(const CubeFactory &);
			~CubeFactory();

			Cube* createCube(int type, int x, int y, int z, int h, int l, Color* color) {
				Cube* cube;

				if (type == 1) {
					cube = this->createFloor(x, y, z, h, l, color);
				}
				else {
					cube = this->createObstacle(x, y, z, h, l, color);
				}

				return cube;
			};

		private:
			Floor* createFloor(int x, int y, int z, int h, int l, Color* color) {
				Floor* floor = new Floor(x, y, z, h, l, color);

				return floor;
			};

			Obstacle* createObstacle(int x, int y, int z, int h, int l, Color* color) {
				Obstacle* obstacle = new Obstacle(x, y, z, h, l, color);

				return obstacle;
			};
};

#endif // CUBEFACTORY_H_INCLUDED
