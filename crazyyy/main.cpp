#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "MapBuilder.h"
#include "Map.h"
#include "CharacterBuilder.h"
#include "Character.h"
#include "sdlglutils.h"
#include <iostream>
#include "math.h"

#define LARGEUR 600
#define HAUTEUR 400
#define FRAMES_PER_SECOND 50

using namespace std;

void printCoord(int x, int y, int z){
	cout << "x:"<< x <<" y:" << y <<" z:"<< z<< endl;
}



int main(int argc, char *argv[]) {
    // Initialisation de la SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Création de la surface d'affichage qui est en OpenGL
    SDL_WM_SetCaption("Crazy Arena",NULL);
    SDL_Surface* ecran = SDL_SetVideoMode(LARGEUR, HAUTEUR, 32, SDL_OPENGL);

    // Initialisation de l'affichage OpenGL
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST); // On prends en compte les zones cachées
    glEnable(GL_TEXTURE_2D); // On active les textures
    //glEnable(GL_FOG);

    gluPerspective (70, (double)LARGEUR/HAUTEUR, 1, 100);
    SDL_Flip(ecran);

    SDL_Event event;
    SDL_EnableKeyRepeat(10,10); // Activation de la répétition de touches



    Uint32 current_time; // Heure actuelle (frames second)
    Uint32 last_time = SDL_GetTicks();
    Uint8 *keystate = SDL_GetKeyState(NULL);

    /*
    int cameraX = 20;
    int cameraY = 20;
    int cameraZ = 20;
	*/

    float cameraX = 13, cameraY = 2, cameraZ = 0, xrot = 0, yrot = 0, angle = 0.0;
    float lastx, lasty;



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

    bool continuer = true;
    while (continuer) {
        SDL_PollEvent(&event);

        switch(event.type) {
            case SDL_QUIT:
                 continuer = false;
                 break;
        }

        if (keystate[SDLK_RIGHT]) {
        	character->right();
        	back = false;
			//x++;
		}
		if (keystate[SDLK_LEFT]) {
			character->left();
			back = false;
			//x--;
		}
		if (keystate[SDLK_UP]) {
			character->front();
			back = false;
			//y++;
		}
		if (keystate[SDLK_DOWN]) {
			if (back == true) {
				//character->back();
				back = false;
			}
			else {
				back = true;
			}
			//y--;
		}
		if(keystate[SDLK_a]){
			cameraY--;

		}
		if(keystate[SDLK_z]){
			cameraY++;
		}
		if(keystate[SDLK_q]){
			cameraZ--;

		}
		if(keystate[SDLK_s]){
			cameraZ++;
		}
		if(keystate[SDLK_w]){
			cameraX--;

		}
		if(keystate[SDLK_x]){
			cameraX++;
		}

		if (keystate[SDLK_r])
		{
			float yrotrad;
			yrotrad = (yrot / 180 * 3.141592654f);
			cameraX += float(cos(yrotrad)) * 0.2;
			cameraZ += float(sin(yrotrad)) * 0.2;
		}

		if (keystate[SDLK_e])
		{
			float yrotrad;
			yrotrad = (yrot / 180 * 3.141592654f);
			cameraX -= float(cos(yrotrad)) * 0.2;
			cameraZ -= float(sin(yrotrad)) * 0.2;
		}

		 if (keystate[SDLK_l])
		    {
			 xrot += 1;
			 if (xrot >360) xrot -= 360;
		    }

		    if (keystate[SDLK_m])
		    {
		    	xrot -= 1;
		    	if (xrot < -360) xrot += 360;
		    }

		    if (keystate[SDLK_o])
		    {
		    float yrotrad;
		    yrotrad = (yrot / 180 * 3.141592654f);
		    cameraX += float(cos(yrotrad)) * 0.2;
		    cameraZ += float(sin(yrotrad)) * 0.2;
		    }

		    if (keystate[SDLK_p])
		    {
		    float yrotrad;
		    yrotrad = (yrot / 180 * 3.141592654f);
		    cameraX -= float(cos(yrotrad)) * 0.2;
		    cameraZ -= float(sin(yrotrad)) * 0.2;
		    }

        // On met en pause (Frame per second)
        current_time = SDL_GetTicks();
		while (current_time - last_time < (1000 / FRAMES_PER_SECOND)) {
			SDL_Delay(1000 / FRAMES_PER_SECOND - (current_time - last_time));
			current_time = SDL_GetTicks();
		}
		last_time = SDL_GetTicks();

		//glScalef(ta,tz,1); //Changement de l'orientation des axes x y z

        glClearColor(0.6, 0.6, 0.6, 1); // Arrière plan

        // Initialisation de la matrice de modélisation
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // On efface la fenêtre (pour la redessiner)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // On place la caméra
        gluLookAt(cameraX, cameraY, cameraZ, 0, 0, 0, 0, 1, 0);
        // On fait tourner le monde (caméra)
        glRotated(0, 1, 1, 0);

        printCoord(cameraX, cameraY, cameraZ);

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
