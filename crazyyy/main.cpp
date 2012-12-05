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
#include "math.h"
#include "cstdlib"
#include "ctime"

#define LARGEUR 800
#define HAUTEUR 600
#define FRAMES_PER_SECOND 30

using namespace std;

//angle of rotation
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle = 0.0;
float upX = 0, upY = 1, upZ = 0;
//float cameraOffset = 10; // our distance from our character

float lastx, lasty;

float camX, camZ;

//COntrôle vitesse touche clavier
double KeysInterval = 80;
Uint32 lastKey;

int main(int argc, char *argv[]) {
	//Change le random (marche pas)
	//srand(time(NULL));

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
	gluPerspective(60, (double) LARGEUR / HAUTEUR, 1, 100);
	SDL_Flip(ecran);

	SDL_Event event;
	SDL_EnableKeyRepeat(10, 10); // Activation de la répétition de touches

	Uint32 current_time; // Heure actuelle (frames second)
	Uint32 last_time = SDL_GetTicks();
	Uint8 *keystate = SDL_GetKeyState(NULL);

	//int cameraX = 0;
	int cameraY = 2;
	//int cameraZ = 0;


	//GLUquadricObj * quad1 = gluNewQuadric();
	//gluQuadricDrawStyle(quad1, GLU_FILL);

	MapBuilder* mp = new MapBuilder();
	Map* map = mp->createMap();

	CharacterBuilder* cb = new CharacterBuilder();
	Character* character = cb->createCharacter();

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

		//Sauvegarde de quand la dernière touche à été pressée

		//cout <<"CT:"<< current_time  << "  LK" <<  lastKey <<  endl;
		//if(current_time > lastKey + KeysInterval){
		if (current_time > lastKey + KeysInterval) {
			if (keystate[SDLK_RIGHT]) {
				lastKey = SDL_GetTicks();
				Position* rightObstaclePosition= character->rightObstaclePosition();

				if (map->getCube(rightObstaclePosition->getX(),rightObstaclePosition->getY(), rightObstaclePosition->getZ()) == 0) {
					character->right();
					moved = true;
				}

				back = false;
				//x++;
			}
			if (keystate[SDLK_LEFT]) {
				lastKey = SDL_GetTicks();
				Position* leftObstaclePosition = character->leftObstaclePosition();

				if (map->getCube(leftObstaclePosition->getX(),leftObstaclePosition->getY(), leftObstaclePosition->getZ()) == 0) {
					character->left();
					moved = true;
				}

				back = false;
				//x--;
			}
			if (keystate[SDLK_UP]) {
				lastKey = SDL_GetTicks();
				Position* frontObstaclePosition = character->frontObstaclePosition();

				//Test du cube sur lequel on marche
				//if (character->isJumping || map->getCube(frontPosition->getX(),
						//frontPosition->getY(), frontPosition->getZ()) != 0) {
					//Test d'un obstacle
					cout<< (map->getCube(frontObstaclePosition->getX(), frontObstaclePosition->getY(),frontObstaclePosition->getZ()) == 0) <<endl;
					if (map->getCube(frontObstaclePosition->getX(), frontObstaclePosition->getY(),
							frontObstaclePosition->getZ()) == 0) {
						character->front();
						moved = true;
					}

				//} else {
					//character->down();
				//}

				back = false;
			}
			if (keystate[SDLK_DOWN]) {
				lastKey = SDL_GetTicks();
				character->rotateBack();
				/*
				if (back == true) {
					//Position* backPosition = character->backPosition();

					//if (map->getCube(backPosition->getX(), backPosition->getY(), backPosition->getZ()) != 0) {
					character->back();
					moved = true;
					//}
				} else {
					back = true;
				}
				*/
			}
			if (keystate[SDLK_SPACE]) {
				//lastKey = SDL_GetTicks();
				//Début du saut
				if(!character->isJumping && character->isOnTheGround)	character->up();
				moved = true;
				back = false;
			}
			if (keystate[SDLK_LSHIFT]) {
				lastKey = SDL_GetTicks();
				//Position* frontPosition = character->frontPosition();

				//if (map->getCube(frontPosition->getX(), frontPosition->getY(), frontPosition->getZ()) != 0) {

				character->down();
				moved = true;
				back = false;
			}
			if (keystate[SDLK_q]) {
				lastKey = SDL_GetTicks();
				character->rotateLeft();
			}
			if (keystate[SDLK_s]) {
				lastKey = SDL_GetTicks();
				character->rotateRight();
			}

			if (moved == true) {
				cout << "x: " << character->getX() << " y:" << character->getY() << " z:"<< character->getZ() << endl;
				moved = false;
			}
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

		camX = character->getX() - float(cos(character->rotAngle / 180 * 3.141592654f));
		camZ = character->getZ() - float(sin(character->rotAngle / 180 * 3.141592654f));

		gluLookAt(camX, character->getY() + cameraY, camZ, character->getX(),
				character->getY() + cameraY, character->getZ(), upX, upY, upZ);

		// On fait tourner le monde (caméra).
		//glTranslated(character->getX(),0,0);
		//glTranslatef(0.0f, 0.0f, -cRadius);
		//glRotated(x, 0, 1, 0);

		// On fait avancer le personnage
		//character->front();

		//le personnage doit continuer de monter
		cout<<"y character:"<< character->y<< " isJumping:" <<  character->isJumping<< " isOnTheGround:"<< character->isOnTheGround << endl;
		if(character->isJumping){
			character->smoothUp();
		}
		else{
			//faire descendre le personnage s'il ne saute pas et n'est pas sur le sol
			if(!character->isJumping && !character->isOnTheGround){
				character->smoothDown();
			}
		}


		//Test pour savoir si le personnage doit tomber (hors saut)
		if(!character->isJumping){
			Position* frontDownPosition = character->frontDownPosition();
			if (map->getCube(frontDownPosition->getX(), frontDownPosition->getY(), frontDownPosition->getZ()) == 0) {
				character->down();
			}
		}

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
