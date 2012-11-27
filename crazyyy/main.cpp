#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "MapBuilder.h"
#include "Map.h"
#include "sdlglutils.h"

#define LARGEUR 600
#define HAUTEUR 400
#define FRAMES_PER_SECOND 50

using namespace std;

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

    int x = 5;
    int y = 5;
    int z = 0;
    //int walkSize = 5;

    //GLUquadricObj * quad1 = gluNewQuadric();
    //gluQuadricDrawStyle(quad1, GLU_FILL);

    MapBuilder* mp = new MapBuilder();
    Map* map = mp->createMap();

    //GLuint floorText = loadTexture("textures/floor.jpg");
    //GLuint wallText = loadTexture("textures/wall.jpg");
    //GLuint earthText = loadTexture("textures/earth.jpg");

    bool continuer = true;
    while (continuer) {
        SDL_PollEvent(&event);

        switch(event.type) {
            case SDL_QUIT:
                 continuer = false;
                 break;
        }

        if (keystate[SDLK_RIGHT]) {
			x++;
		}
		if (keystate[SDLK_LEFT]) {
			x--;
		}
		if (keystate[SDLK_UP]) {
			y++;
		}
		if (keystate[SDLK_DOWN]) {
			y--;
		}

        // On met en pause (Frame per second)
        current_time = SDL_GetTicks();
		while (current_time - last_time < (1000 / FRAMES_PER_SECOND)) {
			SDL_Delay(1000 / FRAMES_PER_SECOND - (current_time - last_time));
			current_time = SDL_GetTicks();
		}
		last_time = SDL_GetTicks();


        glClearColor(0.6, 0.6, 0.6, 1); // Arrière plan

        // Initialisation de la matrice de modélisation
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // On efface la fenêtre (pour la redessiner)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // On place la caméra
        gluLookAt(x, y, z, 0, 0, 0, 0, 1, 0);
        // On fait tourner le monde (caméra)
        //glRotated(x, 0, 1, 0);

        map->draw();

        // Affichage (en double buffering)
        glFlush();
        SDL_GL_SwapBuffers();
    }
    // Fin du programme
    SDL_Quit();
    return 0;
}
