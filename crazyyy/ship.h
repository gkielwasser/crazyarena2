#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

class Ship {
    public :
           double x;
           double y;
           double a;
           int type;
           double speed;
           int life;
           bool shield;
		   double previousSpeed;
		   int bonusType;
		   double color;
           Ship(); // Non impl�ment� donc inutilisable
           Ship(const Ship &); // Constructeur de copie, non impl�ment� donc interdit
           Ship(double x, double y, double a, int type);
           void Draw();
           void Right();
           void Left();
           void Up();
           void Down();
           void Position();
           void decreaseLife();
           void increaseLife();
           void recede();
           double getX();
           double getY();
           double getA();
           double getSpeed();
           int getLife();

		  int getBonusType();
		  void ChangeColor(int color);
		  void Boost();
		  void Shield();
		  void StopBoost();
		  void StopShield();
		  bool visible;
           ~Ship(); // Destructeur
};
#endif // SHIP_H_INCLUDED
