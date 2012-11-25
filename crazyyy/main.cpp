#include <SDL.h>
#include <gl.h>
#include <glu.h>
#include "ship.h"
#include "shoot.h"
#include "asteroid.h"
#include "bonus.h"
#include <vector>
#include <ctime>
#include <cstdlib>

// Taille de la fen�tre
#define LARGEUR 1024
#define HAUTEUR 768
#define FRAMES_PER_SECOND 50

using namespace std;

double randomInt(int a, int b){
    return (a + (rand() % (b-a+1)));
}


int main(int argc, char *argv[]) {
	srand( (unsigned)time( NULL ) );

	// Initialisation de SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Cr�ation de la surface d'affichage qui est en OpenGL
	// (changez le titre si besoin)
	SDL_WM_SetCaption("Astroid", NULL);
	SDL_Surface* ecran = SDL_SetVideoMode(LARGEUR, HAUTEUR, 32, SDL_OPENGL);

	// Initialisation de l'affichage OpenGL
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, LARGEUR, 0, HAUTEUR); // Taille de l'�cran
	SDL_Flip(ecran);

	SDL_Event event;
	SDL_EnableKeyRepeat(10, 10); // Activation de la r�p�tition de touches

	Ship* ship1 = new Ship(300, 300, 90, 1);
	Ship* ship2 = new Ship(500, 500, 45, 2);

	vector<Shoot*> shootVector;
	vector<Asteroid*> asteroidVector;
	vector<Bonus*> bonusVector;

	Asteroid* asteroid = new Asteroid(randomInt(0,LARGEUR),randomInt(0,HAUTEUR),randomInt(0, 180), randomInt(0, 360), randomInt(2, 5),randomInt(5, 30));
	asteroidVector.push_back(asteroid);
	Asteroid* asteroid2 = new Asteroid(randomInt(0,LARGEUR),randomInt(0,HAUTEUR),randomInt(0, 180),  0, randomInt(2, 5),randomInt(5, 30));
	asteroidVector.push_back(asteroid2);
	Asteroid* asteroid3 = new Asteroid(randomInt(0,LARGEUR),randomInt(0,HAUTEUR),randomInt(0, 180), 0, randomInt(3, 8),randomInt(5, 30));
	asteroidVector.push_back(asteroid3);

	Bonus* bonus = new Bonus(randomInt(0,LARGEUR), randomInt(0,HAUTEUR),randomInt(0,180), 0, 1);
	bonusVector.push_back(bonus);
	Bonus* bonus2 = new Bonus(randomInt(0,LARGEUR), randomInt(0,HAUTEUR),randomInt(0,180), 0,2);
	bonusVector.push_back(bonus2);

	Uint32 startBonus = 0;
	Uint32 startBonus2 = 0;

	Uint8 *keystate = SDL_GetKeyState(NULL);
	Uint32 last_time = SDL_GetTicks(); // heure actuelle, derniere mise � jour
	Uint32 current_time;

	Uint32 next_shoot_time_ship1 = 0; // variable enregistrant le moment du dernier tir
	Uint32 shoot_now_ship1; // heure actuelle
	Uint32 next_shoot_time_ship2 = 0; // variable enregistrant le moment du dernier tir
	Uint32 shoot_now_ship2; // heure actuelle

	bool continuer = true;
	while (continuer) {
		SDL_PollEvent(&event);

		switch (event.type) {
			case SDL_QUIT: // fin
				continuer = false;
				break;
		}

		if (keystate[SDLK_ESCAPE]) {
			continuer = false;
		}

		if (ship1->getLife() >  0) {
			// Ship 1
			if (keystate[SDLK_RIGHT]) {
				ship1->Right();
			}
			if (keystate[SDLK_LEFT]) {
				ship1->Left();
			}
			if (keystate[SDLK_UP]) {
				ship1->Up();
			}
			if (keystate[SDLK_DOWN]) {
				ship1->Down();
			}
			if (keystate[SDLK_RCTRL]) {
				shoot_now_ship1 = SDL_GetTicks();

				if (next_shoot_time_ship1 <= shoot_now_ship1) {
					next_shoot_time_ship1 = shoot_now_ship1 + 100;

					Shoot* shoot = new Shoot(ship1);
					shootVector.push_back(shoot);
				}
			}
		}

		if (ship2->getLife() > 0) {
			// Ship 2
			if (keystate[SDLK_d]) {
				ship2->Right();
			}
			if (keystate[SDLK_q]) {
				ship2->Left();
			}
			if (keystate[SDLK_z]) {
				ship2->Up();
			}
			if (keystate[SDLK_s]) {
				ship2->Down();
			}
			if (keystate[SDLK_SPACE]) {
				shoot_now_ship2 = SDL_GetTicks();

				if (next_shoot_time_ship2 <= shoot_now_ship2) {
					next_shoot_time_ship2 = shoot_now_ship2 + 100;

					Shoot* shoot = new Shoot(ship2);
					shootVector.push_back(shoot);
				}
			}
		}

		current_time = SDL_GetTicks();
		while (current_time - last_time < (1000 / FRAMES_PER_SECOND)) {
			// On se met en pause le temps voulu
			SDL_Delay(1000 / FRAMES_PER_SECOND - (current_time - last_time));
			current_time = SDL_GetTicks();
		}
		last_time = SDL_GetTicks();

		// On efface la fenetre
		glClear(GL_COLOR_BUFFER_BIT);

		if (ship1->getLife() > 0) {
			ship1->Draw();
		}
		if (ship2->getLife() > 0) {
			ship2->Draw();
		}

		if (ship1->getLife() > 0 && ship2->getLife() > 0) {
			// On verifie si les vaisseaux ne sont pas en collision
			if ((ship2->getX() > ship1->getX() - 20 && ship2->getX() < ship1->getX() + 20) && (ship2->getY() > ship1->getY() - 20 && ship2->getY() < ship1->getY() + 20)) {
				ship1->decreaseLife();
				ship1->recede();
				ship2->recede();
				ship2->decreaseLife();
			}
		}

		// Pour chaque asteroid
		for (unsigned int i = 0; i < asteroidVector.size(); i++) {
			asteroidVector[i]->rotate(randomInt(0,5));
			asteroidVector[i]->Draw();

			if (ship1->getLife() > 0) {
				// On verifie si l'asteroid n'est pas en collision avec le vaisseau 1
				if ((asteroidVector[i]->getX() > ship1->getX() - 20 && asteroidVector[i]->getX() < ship1->getX() + 20) && (asteroidVector[i]->getY() > ship1->getY() - 20 && asteroidVector[i]->getY() < ship1->getY() + 20)) {
					if(!ship1->shield) {
						ship1->decreaseLife();

						delete asteroidVector[i];
						asteroidVector.erase(asteroidVector.begin() + i);
					}
				}
			}

			if (ship2->getLife() > 0) {
				// On verifie si l'asteroid n'est pas en collision avec le vaisseau 2
				if ((asteroidVector[i]->getX() > ship2->getX() - 20 && asteroidVector[i]->getX() < ship2->getX() + 20) && (asteroidVector[i]->getY() > ship2->getY() - 20 && asteroidVector[i]->getY() < ship2->getY() + 20)) {
					if(!ship2->shield) {
						ship2->decreaseLife();

						delete asteroidVector[i];
						asteroidVector.erase(asteroidVector.begin() + i);
					}
				}
			}
		}

		if (ship1->getLife() > 0) {
			// Test fin de bonus
			if( startBonus != 0 && current_time - startBonus > 5000){
				startBonus = 0;

				if (ship1->getBonusType() == 1) {
					ship1->StopBoost();
				}
				else if(ship1->getBonusType() == 2) {
					ship1->StopShield();
				}
			}
		}

		if (ship2->getLife() > 0) {
			//Test fin de bonus
			if( startBonus2 != 0 && current_time - startBonus2 > 5000){
				startBonus2 = 0;
				if(ship2->getBonusType() == 1) {
					ship2->StopBoost();
				}
				else if(ship2->getBonusType() == 2) {
					ship2->StopShield();
				}
			}
		}

		// Pour chaque Bonus
		for (unsigned int i = 0; i < bonusVector.size(); i++) {
			bonusVector[i]->Draw();

			if (ship1->getLife() > 0) {
				// On verifie si l'asteroid n'est pas en collision avec le vaisseau
				if ((bonusVector[i]->getX() > ship1->getX() - 20 && bonusVector[i]->getX() < ship1->getX() + 20) && (bonusVector[i]->getY() > ship1->getY() - 20 && bonusVector[i]->getY() < ship1->getY() + 20)) {
					startBonus = SDL_GetTicks();
					if(bonusVector[i]->getType()== 1)
						ship1->Boost();
					else if (bonusVector[i]->getType()== 2)
						ship1->Shield();

					delete bonusVector[i];
					bonusVector.erase(bonusVector.begin() + i);
				}
			}

			if (ship2->getLife() > 0) {
				// On verifie si l'asteroid n'est pas en collision avec le vaisseau
				if ((bonusVector[i]->getX() > ship2->getX() - 20 && bonusVector[i]->getX() < ship2->getX() + 20) && (bonusVector[i]->getY() > ship2->getY() - 20 && bonusVector[i]->getY() < ship2->getY() + 20)) {
					startBonus2 = SDL_GetTicks();

					if(bonusVector[i]->getType()== 1)
						ship2->Boost();
					else if (bonusVector[i]->getType()== 2)
						ship2->Shield();

					delete bonusVector[i];
					bonusVector.erase(bonusVector.begin() + i);
				}
			}
		}

		// Pour chaque tir
		for (unsigned int i = 0; i < shootVector.size(); i++) {
			if (shootVector[i]->getX() > 0 && shootVector[i]->getX() < LARGEUR) {
				if (shootVector[i]->getY() > 0 && shootVector[i]->getY() < HAUTEUR) {
					shootVector[i]->Draw();

					// Pour chaque asteroid
					for (unsigned int j = 0; j < asteroidVector.size(); j++) {
						// On verifie que le tir n'est pas en collision avec un asteroid
						if ((shootVector[i]->getX() > asteroidVector[j]->getX() - 20 && shootVector[i]->getX() < asteroidVector[j]->getX() + 20) && (shootVector[i]->getY() > asteroidVector[j]->getY() - 20 && shootVector[i]->getY() < asteroidVector[j]->getY() + 20)) {
							delete asteroidVector[j];
							asteroidVector.erase(asteroidVector.begin() + j);
						}
					}

					if (ship1->getLife() > 0) {
						// On verifie si le tir n'est pas en collision contre le vaisseau 1
						if ((shootVector[i]->getX() > ship1->getX() - 20 && shootVector[i]->getX() < ship1->getX() + 20) && (shootVector[i]->getY() > ship1->getY() - 20 && shootVector[i]->getY() < ship1->getY() + 20)) {
							// On vérifie que le tir du vaisseau 1 ne touche pas le vaisseau 1
							if (shootVector[i]->getShip() != ship1) {
								ship1->decreaseLife();
								ship2->increaseLife();

								delete shootVector[i];
								shootVector.erase(shootVector.begin() + i);
							}
						}
					}

					if (ship2->getLife() > 0) {
						// On verifie si le tir n'est pas en collision contre le vaisseau 2
						if ((shootVector[i]->getX() > ship2->getX() - 20 && shootVector[i]->getX() < ship2->getX() + 20) && (shootVector[i]->getY() > ship2->getY() - 20 && shootVector[i]->getY() < ship2->getY() + 20)) {
							// On vérifie que le tir du vaisseau 2 ne touche pas le vaisseau 2
							if (shootVector[i]->getShip() != ship2) {
								ship2->decreaseLife();
								ship1->increaseLife();

								delete shootVector[i];
								shootVector.erase(shootVector.begin() + i);
							}
						}
					}
				}
				else {
					delete shootVector[i];
					shootVector.erase(shootVector.begin() + i);
				}
			}
			else {
				delete shootVector[i];
				shootVector.erase(shootVector.begin() + i);
			}
		}

		if (asteroidVector.size() < 1) {
				Asteroid* asteroid = new Asteroid(randomInt(0,LARGEUR),randomInt(0,HAUTEUR),randomInt(0, 180), randomInt(0, 360), randomInt(2, 5),randomInt(5, 30));
				asteroidVector.push_back(asteroid);
				Asteroid* asteroid2 = new Asteroid(randomInt(0,LARGEUR),randomInt(0,HAUTEUR),randomInt(0, 180),  0, randomInt(2, 5),randomInt(5, 30));
				asteroidVector.push_back(asteroid2);
				Asteroid* asteroid3 = new Asteroid(randomInt(0,LARGEUR),randomInt(0,HAUTEUR),randomInt(0, 180), 0, randomInt(3, 8),randomInt(5, 30));
				asteroidVector.push_back(asteroid3);
		}

		if (bonusVector.size() < 1){
			Bonus* bonus = new Bonus(randomInt(0,LARGEUR), randomInt(0,HAUTEUR),randomInt(0,180), 0, 1);
				bonusVector.push_back(bonus);
				Bonus* bonus2 = new Bonus(randomInt(0,LARGEUR), randomInt(0,HAUTEUR),randomInt(0,180), 0,2);
				bonusVector.push_back(bonus2);
		}

		if (ship1->getLife() == 0 && ship2->getLife() == 0) {
			continuer = false;
		}

		// Affichage (en double buffering)
		glFlush();
		SDL_GL_SwapBuffers();
	}

	// Fin du programme
	SDL_Quit();
	return 0;
}
