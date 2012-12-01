#ifndef MAPBUILDER_H_INCLUDED
#define MAPBUILDER_H_INCLUDED
#include "Map.h"
#include "Cube.h"
#include "CubeFactory.h"
#include "Plate.h"
#include <vector>

using namespace std;

class MapBuilder {
		public:
			MapBuilder(){};
			MapBuilder(const MapBuilder &);
			~MapBuilder();

			Map* createMap() {
				CubeFactory* cf = new CubeFactory();

				//Création de 2 couleurs(temporaire)
				Color* blue = new Color(51, 102, 255);
				Color* blue2 = new Color(51, 204, 255);

				//Colonne 1a
				//Coins haut gauche(0,0)
				vector<Cube*> cubes;
				cubes.push_back(cf->createCube(0, 0, 0, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 1, 0, 0, 1, 1, blue2));
				cubes.push_back(cf->createCube(0, 2, 0, 0, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 3, 0, 0, 1, 1, blue2));

				cubes.push_back(cf->createCube(0, 0, 0, 1, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 1, 0, 1, 1, 1, blue2));
				cubes.push_back(cf->createCube(0, 2, 0, 1, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 3, 0, 1, 1, 1, blue2));

				cubes.push_back(cf->createCube(0, 0, 0, 2, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 1, 0, 2, 1, 1, blue2));
				cubes.push_back(cf->createCube(0, 2, 0, 2, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 3, 0, 2, 1, 1, blue2));

				cubes.push_back(cf->createCube(0, 0, 0, 3, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 1, 0, 3, 1, 1, blue2));
				cubes.push_back(cf->createCube(0, 2, 0, 3, 1, 1, blue));
				cubes.push_back(cf->createCube(0, 3, 0, 3, 1, 1, blue2));

				//Colonne 1
				vector<Cube*> cubes2;
				cubes2.push_back(cf->createCube(0, 0, 0, 4, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 1, 0, 4, 1, 1, blue2));
				cubes2.push_back(cf->createCube(0, 2, 0, 4, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 3, 0, 4, 1, 1, blue2));

				cubes2.push_back(cf->createCube(0, 0, 0, 5, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 1, 0, 5, 1, 1, blue2));
				cubes2.push_back(cf->createCube(0, 2, 0, 5, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 3, 0, 5, 1, 1, blue2));

				cubes2.push_back(cf->createCube(0, 0, 0, 6, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 1, 0, 6, 1, 1, blue2));
				cubes2.push_back(cf->createCube(0, 2, 0, 6, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 3, 0, 6, 1, 1, blue2));

				cubes2.push_back(cf->createCube(0, 0, 0, 7, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 1, 0, 7, 1, 1, blue2));
				cubes2.push_back(cf->createCube(0, 2, 0, 7, 1, 1, blue));
				cubes2.push_back(cf->createCube(0, 3, 0, 7, 1, 1, blue2));

				//Colonne 2
				vector<Cube*> cubes3;
				cubes3.push_back(cf->createCube(0, 4, 0, 0, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 5, 0, 0, 1, 1, blue2));
				cubes3.push_back(cf->createCube(0, 6, 0, 0, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 7, 0, 0, 1, 1, blue2));

				cubes3.push_back(cf->createCube(0, 4, 0, 1, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 5, 0, 1, 1, 1, blue2));
				cubes3.push_back(cf->createCube(0, 6, 0, 1, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 7, 0, 1, 1, 1, blue2));

				cubes3.push_back(cf->createCube(0, 4, 0, 2, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 5, 0, 2, 1, 1, blue2));
				cubes3.push_back(cf->createCube(0, 6, 0, 2, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 7, 0, 2, 1, 1, blue2));

				cubes3.push_back(cf->createCube(0, 4, 0, 3, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 5, 0, 3, 1, 1, blue2));
				cubes3.push_back(cf->createCube(0, 6, 0, 3, 1, 1, blue));
				cubes3.push_back(cf->createCube(0, 7, 0, 3, 1, 1, blue2));

				//Colonne 3
				vector<Cube*> cubes4;
				cubes4.push_back(cf->createCube(0, 8, 0, 0, 1, 1, blue));
				cubes4.push_back(cf->createCube(0, 9, 0, 0, 1, 1, blue2));
				cubes4.push_back(cf->createCube(0, 10, 0, 0, 1, 1, blue));
				cubes4.push_back(cf->createCube(0, 11, 0, 0, 1, 1, blue2));

				cubes4.push_back(cf->createCube(0, 8, 0, 1, 1, 1, blue));
				cubes4.push_back(cf->createCube(0, 9, 0, 1, 1, 1, blue2));
				cubes4.push_back(cf->createCube(0, 10, 0, 1, 1, 1, blue));
				cubes4.push_back(cf->createCube(0, 11, 0, 1, 1, 1, blue2));

				cubes4.push_back(cf->createCube(0, 8, 0, 2, 1, 1, blue));
				cubes4.push_back(cf->createCube(0, 9, 0, 2, 1, 1, blue2));
				cubes4.push_back(cf->createCube(0, 10, 0, 2, 1, 1, blue));
				cubes4.push_back(cf->createCube(0, 11, 0, 2, 1, 1, blue2));

				cubes4.push_back(cf->createCube(0, 8, 0, 3, 1, 1, blue));
				cubes4.push_back(cf->createCube(0, 9, 0, 3, 1, 1, blue2));
				cubes4.push_back(cf->createCube(0, 10, 0, 3, 1, 1, blue));
				cubes4.push_back(cf->createCube(0, 11, 0, 3, 1, 1, blue2));

				//Création d'une plate avec son vecteur de cubes
				Plate* plate = new Plate(cubes);
				Plate* plate2 = new Plate(cubes2);
				Plate* plate3 = new Plate(cubes3);
				Plate* plate4 = new Plate(cubes4);

				//Création d'un vecteur de plate
				vector<Plate*> plates;

				plates.push_back(plate);
				plates.push_back(plate2);
				plates.push_back(plate3);
				plates.push_back(plate4);

				//Création d'une map avec son vecteur de plate
				Map* map = new Map(plates);

 				return map;
			};
			/*
			Plate* createPlaque(){
				//Plate* plate = new Plate(cubes);
				return plate;
			}
			*/
};

#endif // MAPBUILDER_H_INCLUDED
