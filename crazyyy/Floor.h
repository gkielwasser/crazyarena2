#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED

class Bonus {
		public:
			   Bonus(); // Non impl�ment� donc inutilisable
			   Bonus(const Bonus &); // Constructeur de copie, non impl�ment� donc interdit
			   Bonus(int x, int y, int a, int speed, int type);
	           ~Bonus(); // Destructeur
	           int x,y,a,speed,type;
	           void Draw();
	           void Position();
	           double getX();

	           double getY();

	           double getA();
	           int getType();


};

#endif // BONUS_H_INCLUDED
