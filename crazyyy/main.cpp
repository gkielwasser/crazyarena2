#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "MapBuilder.h"
#include "Map.h"
#include "CharacterBuilder.h"
#include "Character.h"
#include "Position.h"
#include "sdlglutils.h"
#include <iostream>

#define LARGEUR 600
#define HAUTEUR 400
#define FRAMES_PER_SECOND 25

using namespace std;

//angle of rotation
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle = 0.0;
float upX = 0, upY = 1, upZ = 0;
//float cameraOffset = 10; // our distance from our character

float lastx, lasty;

int main(int argc, char *argv[]) {
	// Initialisation de la SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Création de la surface d'affichage qui est en OpenGL
	SDL_WM_SetCaption("Crazy Arena", NULL);
	SDL_Surface* ecran = SDL_SetVideoMode(LARGEUR, HAUTEUR, 32, SDL_OPENGL);

	// Initialisation de l'affichage OpenGL
	/* Control the Projection */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST); // On prends en compte les zones cachées
	glEnable(GL_TEXTURE_2D); // On active les textures
	//glEnable(GL_FOG);

	/*
	 *  Explications gluPerspective(détails:http://www.siteduzero.com/tutoriel-3-421544-la-matrice-de-projection.html)
	 *  	p1: angle (exemple: 70,30,100: angle de vue de la scène-> plus celui-ci est petit, plus on a l'impression de faire un zoom sur la scène
	 *  	p2: ratio: largeur/hauteur
	 *  	p3: near:
	 *  	p4: far: pour qu'un objet puisse s'afficher sur l'écran, il faut qu'il se situe entre les zones near et far, sinon il ne sera pas affiché.
	 */
	//gluPerspective (20, (double)LARGEUR/HAUTEUR, 1, 100);
	gluPerspective(45, (double) LARGEUR / HAUTEUR, 1, 100);
	SDL_Flip(ecran);

	SDL_Event event;
	SDL_EnableKeyRepeat(10, 10); // Activation de la répétition de touches

	Uint32 current_time; // Heure actuelle (frames second)
	Uint32 last_time = SDL_GetTicks();
	Uint8 *keystate = SDL_GetKeyState(NULL);

	int cameraX = -5;
	int cameraY = 2;
	int cameraZ = 0;
	/* Passer en mode Création de la carte: x=38;
	 * Passer en mode Jeu: x=132
	 *
	 * La touche A permet de changer le mode
	 */

	//GLUquadricObj * quad1 = gluNewQuadric();
	//gluQuadricDrawStyle(quad1, GLU_FILL);

	MapBuilder* mp = new MapBuilder();
	Map* map = mp->createMap();

	CharacterBuilder* cb = new CharacterBuilder();
	Character* character = cb->createCharacter();

	//GLuint floorText = loadTexture("textures/floor.jpg");
	//GLuint wallText = loadTexture("textures/wall.jpg");
	//GLuint earthText = loadTexture("textures/earth.jpg");

	bool back = false;
	bool moved = false;

	bool continuer = true;
	while (continuer) {
		SDL_PollEvent(&event);

		switch (event.type) {
		case SDL_QUIT:
			continuer = false;
			break;
		}

		if (keystate[SDLK_RIGHT]) {
			Position* rightPosition = character->rightPosition();

			if (character->isJumping || map->getCube(rightPosition->getX(), rightPosition->getY(),
					rightPosition->getZ()) != 0) {
				character->right();
				moved = true;
			}

			back = false;
			//x++;
		}
		if (keystate[SDLK_LEFT]) {
			Position* leftPosition = character->leftPosition();

			if (character->isJumping || map->getCube(leftPosition->getX(), leftPosition->getY(),
					leftPosition->getZ()) != 0) {
				character->left();
				moved = true;
			}

			back = false;
			//x--;
		}
		if (keystate[SDLK_UP]) {
			Position* frontPosition = character->frontPosition();

			if (character->isJumping || map->getCube(frontPosition->getX(), frontPosition->getY(),
					frontPosition->getZ()) != 0) {
				character->front();
				moved = true;
			}

			back = false;
			//cameraZ--;
		}
		if (keystate[SDLK_DOWN]) {
			if (back == true) {
				Position* backPosition = character->backPosition();

				if (map->getCube(backPosition->getX(), backPosition->getY(), backPosition->getZ()) != 0) {
					character->back();
					moved = true;
				}

				character->back();
				back = false;
			} else {
				back = true;
			}
			//y--;
		}
		if (keystate[SDLK_SPACE]) {
			//Position* frontPosition = character->frontPosition();

			//if (map->getCube(frontPosition->getX(), frontPosition->getY(), frontPosition->getZ()) != 0) {

			//On regarde quand a été fait le dernier faut
			if(character->lastJump_time + 1000 < current_time){
				character->up();
				moved = true;
			}
			//}

			back = false;
		}
		if (keystate[SDLK_LSHIFT]) {
			//Position* frontPosition = character->frontPosition();

			//if (map->getCube(frontPosition->getX(), frontPosition->getY(), frontPosition->getZ()) != 0) {

			character->down();
			moved = true;

			back = false;
		}
		if (keystate[SDLK_q]) {
			cameraY++;
			cout << "cameraX:" << cameraY << endl;
		}
		if (keystate[SDLK_s]) {
			cameraY--;
			cout << "cameraX:" << cameraY << endl;
		}

		if (moved == true) {
			cout << "x: " << character->getX() << " y:" << character->getY() << " z:"
					<< character->getZ() << endl;
			moved = false;
		}

		// On met en pause (Frame per second)
		current_time = SDL_GetTicks();
		while (current_time - last_time < (1000 / FRAMES_PER_SECOND)) {
			SDL_Delay(1000 / FRAMES_PER_SECOND - (current_time - last_time));
			current_time = SDL_GetTicks();
		}
		last_time = SDL_GetTicks();

		glClearColor(0, 0, 0, 1); // Arrière plan

		/* Control the Model / View */
		glMatrixMode(GL_MODELVIEW); // Choix de la matrice
		glLoadIdentity(); //Initialisation/RAZ de la matrice model/view pour ne pas garder les anciennes valeurs

		// On efface la fenêtre (pour la redessiner)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// On place la caméra(cela permet d'avancer automatiquement la caméra en incrémentant les variable cameraX,Y,Z).
		//cameraZ--;
		gluLookAt(character->getX() + cameraX, character->getY() + cameraY,
				character->getZ() + cameraZ, character->getX(), character->getY()+2,
				character->getZ(), upX, upY, upZ);
		//gluLookAt(cameraX, cameraY, cameraZ, 0, 0, 0, upX, upY, upZ);

		// On fait tourner le monde (caméra).
		//glTranslated(character->getX(),0,0);
		//glTranslatef(0.0f, 0.0f, -cRadius);
		//glRotated(x, 0, 1, 0);

		// On fait avancer le personnage
		//character->front();

		//Faire retomber le perso
		//cout<<(character->getJumpStartTime() + 20 < current_time)<<endl;
		//jumpTime=SDL_GetTicks();

		if (character->isJumping && (current_time > character->getJumpStartTime() + 500)) {
			//cout<<current_time<<"  /   "<< character->getJumpStartTime()<<endl;
			character->down();
		}
		//cout<<"time:"<<current_time<<endl;

		// On dessine tous les éléments
		map->draw();
		character->draw();

		// Affichage (en double buffering)
		glFlush();
		SDL_GL_SwapBuffers();
	}
	// Fin du programme
	SDL_Quit();
	return 0;
}
