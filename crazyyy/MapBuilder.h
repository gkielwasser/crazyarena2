#ifndef MAPBUILDER_H_INCLUDED
#define MAPBUILDER_H_INCLUDED
#include "Map.h"
#include "Cube.h"
#include "CubeFactory.h"
#include "PlateBuilder.h"
#include "Plate.h"
#include <vector>

using namespace std;

class MapBuilder {
public:
	MapBuilder() {
	}
	;
	MapBuilder(const MapBuilder &);
	~MapBuilder();

	Map* createMap() {
		PlateBuilder* p = new PlateBuilder();

		vector<Plate*> plates;

		plates.push_back(p->createPlate(0, 0, 0));
		plates.push_back(p->createPlate(4, 0, 0));
		plates.push_back(p->createPlate(8, 0, 0));
		plates.push_back(p->createPlate(12, 0, 0));
		plates.push_back(p->createPlate(16, 0, 0));
		plates.push_back(p->createPlate(20, 0, 0));
		plates.push_back(p->createPlate(24, 0, 0));
		plates.push_back(p->createPlate(28, 0, 0));
		plates.push_back(p->createPlate(32, 0, 0));
		plates.push_back(p->createPlate(36, 0, 0));
		plates.push_back(p->createPlate(40, 0, 0));
		plates.push_back(p->createPlate(44, 0, 0));
		plates.push_back(p->createPlate(48, 0, 0));
		plates.push_back(p->createPlate(52, 0, 0));
		plates.push_back(p->createPlate(56, 0, 0));
		plates.push_back(p->createPlate(60, 0, 0));
		plates.push_back(p->createPlate(64, 0, 0));
		plates.push_back(p->createPlate(68, 0, 0));
		plates.push_back(p->createPlate(72, 0, 0));
		plates.push_back(p->createPlate(76, 0, 0));

		//Ligne 2
		plates.push_back(p->createPlate(0, 0, 4));
		plates.push_back(p->createPlate(20, 0, 4));
		plates.push_back(p->createPlate(76, 0, 4));

		//Ligne 3
		plates.push_back(p->createPlate(0, 0, 8));
		plates.push_back(p->createPlate(4, 0, 8));
		plates.push_back(p->createPlate(8, 0, 8));
		plates.push_back(p->createPlate(12, 0, 8));
		plates.push_back(p->createPlate(16, 0, 8));
		plates.push_back(p->createPlate(20, 0, 8));
		plates.push_back(p->createPlate(24, 0, 8));
		plates.push_back(p->createPlate(28, 0, 8));
		plates.push_back(p->createPlate(32, 0, 8));
		plates.push_back(p->createPlate(36, 0, 8));
		plates.push_back(p->createPlate(40, 0, 8));
		plates.push_back(p->createPlate(76, 0, 8));

		//Ligne 3 LVL3
		/*plates.push_back(p->createPlate(0, 2, 8));
		 plates.push_back(p->createPlate(4, 2, 8));
		 plates.push_back(p->createPlate(8, 2, 8));
		 plates.push_back(p->createPlate(12, 2, 8));
		 plates.push_back(p->createPlate(16, 2, 8));
		 plates.push_back(p->createPlate(20, 2, 8));*/

		//Ligne 4
		plates.push_back(p->createPlate(0, 0, 12));
		plates.push_back(p->createPlate(16, 0, 12));
		plates.push_back(p->createPlate(40, 0, 12));
		plates.push_back(p->createPlate(76, 0, 12));

		//Ligne 5
		plates.push_back(p->createPlate(0, 0, 16));
		plates.push_back(p->createPlate(8, 0, 16));
		plates.push_back(p->createPlate(12, 0, 16));
		plates.push_back(p->createPlate(16, 0, 16));
		plates.push_back(p->createPlate(20, 0, 16));
		plates.push_back(p->createPlate(24, 0, 16));
		plates.push_back(p->createPlate(28, 0, 16));
		plates.push_back(p->createPlate(32, 0, 16));
		plates.push_back(p->createPlate(40, 0, 16));
		plates.push_back(p->createPlate(44, 0, 16));
		plates.push_back(p->createPlate(48, 0, 16));
		plates.push_back(p->createPlate(52, 0, 16));
		plates.push_back(p->createPlate(56, 0, 16));
		plates.push_back(p->createPlate(60, 0, 16));
		plates.push_back(p->createPlate(64, 0, 16));
		plates.push_back(p->createPlate(68, 0, 16));
		plates.push_back(p->createPlate(76, 0, 16));

		//Ligne 6
		plates.push_back(p->createPlate(0, 0, 20));
		plates.push_back(p->createPlate(4, 0, 20));
		plates.push_back(p->createPlate(8, 0, 20));
		plates.push_back(p->createPlate(32, 0, 20));
		plates.push_back(p->createPlate(68, 0, 20));
		plates.push_back(p->createPlate(76, 0, 20));

		// Ligne 7
		plates.push_back(p->createPlate(0, 0, 24));
		plates.push_back(p->createPlate(8, 0, 24));
		plates.push_back(p->createPlate(12, 0, 24));
		plates.push_back(p->createPlate(16, 0, 24));
		plates.push_back(p->createPlate(20, 0, 24));
		plates.push_back(p->createPlate(24, 0, 24));
		plates.push_back(p->createPlate(28, 0, 24));
		plates.push_back(p->createPlate(32, 0, 24));
		plates.push_back(p->createPlate(36, 0, 24));
		plates.push_back(p->createPlate(40, 0, 24));
		plates.push_back(p->createPlate(44, 0, 24));
		plates.push_back(p->createPlate(48, 0, 24));
		plates.push_back(p->createPlate(52, 0, 24));
		plates.push_back(p->createPlate(56, 0, 24));
		plates.push_back(p->createPlate(60, 0, 24));
		plates.push_back(p->createPlate(68, 0, 24));
		plates.push_back(p->createPlate(76, 0, 24));

		// Ligne 8
		plates.push_back(p->createPlate(0, 0, 28));
		plates.push_back(p->createPlate(8, 0, 28));
		plates.push_back(p->createPlate(24, 0, 28));
		plates.push_back(p->createPlate(60, 0, 28));
		plates.push_back(p->createPlate(64, 0, 28));
		plates.push_back(p->createPlate(68, 0, 28));
		plates.push_back(p->createPlate(72, 0, 28));
		plates.push_back(p->createPlate(76, 0, 28));

		// Ligne 9
		plates.push_back(p->createPlate(0, 0, 32));
		plates.push_back(p->createPlate(8, 0, 32));
		plates.push_back(p->createPlate(12, 0, 32));
		plates.push_back(p->createPlate(16, 0, 32));
		plates.push_back(p->createPlate(20, 0, 32));
		plates.push_back(p->createPlate(24, 0, 32));
		plates.push_back(p->createPlate(28, 0, 32));
		plates.push_back(p->createPlate(60, 0, 32));
		plates.push_back(p->createPlate(76, 0, 32));

		// Ligne 10
		plates.push_back(p->createPlate(0, 0, 36));
		plates.push_back(p->createPlate(28, 0, 36));
		plates.push_back(p->createPlate(32, 0, 36));
		plates.push_back(p->createPlate(36, 0, 36));
		plates.push_back(p->createPlate(40, 0, 36));
		plates.push_back(p->createPlate(44, 0, 36));
		plates.push_back(p->createPlate(48, 0, 36));
		plates.push_back(p->createPlate(52, 0, 36));
		plates.push_back(p->createPlate(60, 0, 36));
		plates.push_back(p->createPlate(76, 0, 36));

		// Ligne 11
		plates.push_back(p->createPlate(0, 0, 40));
		plates.push_back(p->createPlate(8, 0, 40));
		plates.push_back(p->createPlate(12, 0, 40));
		plates.push_back(p->createPlate(16, 0, 40));
		plates.push_back(p->createPlate(20, 0, 40));
		plates.push_back(p->createPlate(28, 0, 40));
		plates.push_back(p->createPlate(36, 0, 40));
		plates.push_back(p->createPlate(52, 0, 40));
		plates.push_back(p->createPlate(60, 0, 40));
		plates.push_back(p->createPlate(64, 0, 40));
		plates.push_back(p->createPlate(68, 0, 40));
		plates.push_back(p->createPlate(76, 0, 40));

		// Ligne 12
		plates.push_back(p->createPlate(0, 0, 44));
		plates.push_back(p->createPlate(8, 0, 44));
		plates.push_back(p->createPlate(20, 0, 44));
		plates.push_back(p->createPlate(28, 0, 44));
		plates.push_back(p->createPlate(36, 0, 44));
		plates.push_back(p->createPlate(52, 0, 44));
		plates.push_back(p->createPlate(68, 0, 44));
		plates.push_back(p->createPlate(76, 0, 44));

		// Ligne 13
		plates.push_back(p->createPlate(0, 0, 48));
		plates.push_back(p->createPlate(8, 0, 48));
		plates.push_back(p->createPlate(20, 0, 48));
		plates.push_back(p->createPlate(28, 0, 48));
		plates.push_back(p->createPlate(36, 0, 48));
		plates.push_back(p->createPlate(40, 0, 48));
		plates.push_back(p->createPlate(52, 0, 48));
		plates.push_back(p->createPlate(68, 0, 48));
		plates.push_back(p->createPlate(76, 0, 48));

		// Ligne 14
		plates.push_back(p->createPlate(0, 0, 52));
		plates.push_back(p->createPlate(8, 0, 52));
		plates.push_back(p->createPlate(20, 0, 52));
		plates.push_back(p->createPlate(24, 0, 52));
		plates.push_back(p->createPlate(28, 0, 52));
		plates.push_back(p->createPlate(40, 0, 52));
		plates.push_back(p->createPlate(44, 0, 52));
		plates.push_back(p->createPlate(48, 0, 52));
		plates.push_back(p->createPlate(52, 0, 52));
		plates.push_back(p->createPlate(56, 0, 52));
		plates.push_back(p->createPlate(60, 0, 52));
		plates.push_back(p->createPlate(64, 0, 52));
		plates.push_back(p->createPlate(68, 0, 52));
		plates.push_back(p->createPlate(76, 0, 52));

		// Ligne 15
		plates.push_back(p->createPlate(0, 0, 56));
		plates.push_back(p->createPlate(8, 0, 56));
		plates.push_back(p->createPlate(20, 0, 56));
		plates.push_back(p->createPlate(28, 0, 56));
		plates.push_back(p->createPlate(32, 0, 56));
		plates.push_back(p->createPlate(40, 0, 56));
		plates.push_back(p->createPlate(56, 0, 56));
		plates.push_back(p->createPlate(76, 0, 56));

		// Ligne 16
		plates.push_back(p->createPlate(0, 0, 60));
		plates.push_back(p->createPlate(8, 0, 60));
		plates.push_back(p->createPlate(20, 0, 60));
		plates.push_back(p->createPlate(32, 0, 60));
		plates.push_back(p->createPlate(40, 0, 60));
		plates.push_back(p->createPlate(44, 0, 60));
		plates.push_back(p->createPlate(48, 0, 60));
		plates.push_back(p->createPlate(52, 0, 60));
		plates.push_back(p->createPlate(56, 0, 60));
		plates.push_back(p->createPlate(60, 0, 60));
		plates.push_back(p->createPlate(64, 0, 60));
		plates.push_back(p->createPlate(68, 0, 60));
		plates.push_back(p->createPlate(72, 0, 60));
		plates.push_back(p->createPlate(76, 0, 60));

		// Ligne 17
		plates.push_back(p->createPlate(0, 0, 64));
		plates.push_back(p->createPlate(8, 0, 64));
		plates.push_back(p->createPlate(20, 0, 64));
		plates.push_back(p->createPlate(32, 0, 64));
		plates.push_back(p->createPlate(40, 0, 64));
		plates.push_back(p->createPlate(68, 0, 64));
		plates.push_back(p->createPlate(76, 0, 64));

		// Ligne 18
		plates.push_back(p->createPlate(0, 0, 68));
		plates.push_back(p->createPlate(4, 0, 68));
		plates.push_back(p->createPlate(8, 0, 68));
		plates.push_back(p->createPlate(12, 0, 68));
		plates.push_back(p->createPlate(16, 0, 68));
		plates.push_back(p->createPlate(20, 0, 68));
		plates.push_back(p->createPlate(24, 0, 68));
		plates.push_back(p->createPlate(28, 0, 68));
		plates.push_back(p->createPlate(32, 0, 68));
		plates.push_back(p->createPlate(36, 0, 68));
		plates.push_back(p->createPlate(40, 0, 68));
		plates.push_back(p->createPlate(44, 0, 68));
		plates.push_back(p->createPlate(48, 0, 68));
		plates.push_back(p->createPlate(52, 0, 68));
		plates.push_back(p->createPlate(56, 0, 68));
		plates.push_back(p->createPlate(60, 0, 68));
		plates.push_back(p->createPlate(64, 0, 68));
		plates.push_back(p->createPlate(68, 0, 68));
		plates.push_back(p->createPlate(76, 0, 68));

		// Ligne 19
		plates.push_back(p->createPlate(0, 0, 72));
		plates.push_back(p->createPlate(40, 0, 72));
		plates.push_back(p->createPlate(76, 0, 72));

		// Ligne 20
		plates.push_back(p->createPlate(0, 0, 76));
		plates.push_back(p->createPlate(4, 0, 76));
		plates.push_back(p->createPlate(8, 0, 76));
		plates.push_back(p->createPlate(12, 0, 76));
		plates.push_back(p->createPlate(16, 0, 76));
		plates.push_back(p->createPlate(20, 0, 76));
		plates.push_back(p->createPlate(24, 0, 76));
		plates.push_back(p->createPlate(28, 0, 76));
		plates.push_back(p->createPlate(32, 0, 76));
		plates.push_back(p->createPlate(36, 0, 76));
		plates.push_back(p->createPlate(40, 0, 76));
		plates.push_back(p->createPlate(44, 0, 76));
		plates.push_back(p->createPlate(48, 0, 76));
		plates.push_back(p->createPlate(52, 0, 76));
		plates.push_back(p->createPlate(56, 0, 76));
		plates.push_back(p->createPlate(60, 0, 76));
		plates.push_back(p->createPlate(64, 0, 76));
		plates.push_back(p->createPlate(68, 0, 76));
		plates.push_back(p->createPlate(72, 0, 76));
		plates.push_back(p->createPlate(76, 0, 76));

		//Ligne 6 LVL3
		/*plates.push_back(p->createPlate(0, 2, 20));
		 plates.push_back(p->createPlate(4, 2, 20));
		 plates.push_back(p->createPlate(8, 2, 20));*/

		//Niveau 0
		/*plates.push_back(p->createPlate(0, -4, 12));
		 plates.push_back(p->createPlate(4, -4, 12));
		 plates.push_back(p->createPlate(8, -4, 12));
		 plates.push_back(p->createPlate(12, -4, 12));
		 plates.push_back(p->createPlate(16, -4, 12));
		 plates.push_back(p->createPlate(20, -4, 12));*/
		//Création d'une map avec son vecteur de plate
		Map* map = new Map(plates);

		return map;
	}
};

#endif // MAPBUILDER_H_INCLUDED
