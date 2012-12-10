#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

#include "Color.h"
#include "Plate.h"

class Plate;
class Cube {

public:
	Plate* plate;
	int x;
	int y;
	int z;
	int h;
	int l;
	int xmap;
	int ymap;
	int zmap;
	int xcol;
	int ycol;
	int zcol;


	/*
	 * Textures
	 * Ordre:Haut,Bas,Gauche,Droite,Devant,Derrière
	 */
	GLuint* textures;
	Color* color;

	Cube(int x, int y, int z, int h, int l, int xmap, int ymap, int zmap, Color* color, GLuint* textures,Plate* plate) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->h = h;
		this->l = l;
		this->xmap = xmap;
		this->ymap = ymap;
		this->zmap = zmap;
		this->color = color;
		this->textures = textures;
		this->xcol = xmap - 1;
		this->plate = plate;
	}

	~Cube();

	//Utiliser la fontion glScale() pour agrandir réduire le cube
	virtual void draw() {
	}

	int getX() {
		return this->x;
	}

	int getY() {
		return this->y;
	}

	int getZ() {
		return this->z;
	}

	int getXMap() {
		return this->xmap;
	}

	int getYMap() {
		return this->ymap;
	}

	int getZMap() {
		return this->zmap;
	}

	int getXCol() {
		return this->xcol;
	}

	Plate* getPlate(){
		return this->plate;
	}
};

#endif // CUBE_H_INCLUDED
