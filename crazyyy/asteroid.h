#ifndef ASTEROID_H_INCLUDED
#define ASTEROID_H_INCLUDED

class Asteroid {
    public :
           double x;
           double y;
           double a;
           double speed;
           int rot;
           int height;
           int width;
           Asteroid(); // Non impl�ment� donc inutilisable
           Asteroid(const Asteroid &); // Constructeur de copie, non impl�ment� donc interdit
           Asteroid(int x, int y, int a, int rot,int  speed, int height);
           void Draw();
           void Position();
           double getX();
           double getY();
           double getA();
           double randomInt(int a, int b);
           void rotate(int rand);
           ~Asteroid(); // Destructeur
};
#endif // ASTEROID_H_INCLUDED
