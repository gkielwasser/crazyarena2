#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED

class Bonus {
		public:
			   Bonus(); // Non impl�ment� donc inutilisable
			   Bonus(const Bonus &); // Constructeur de copie, non impl�ment� donc interdit
			   Bonus(float x, float y, float z, float speed, int type);
	           ~Bonus(); // Destructeur
	           float x,y,z,speed;
	           int type;
	           void Draw();
	           void Position();
	           float getX();

	           float getY();

	           float getA();
	           int getType();


};

#endif // BONUS_H_INCLUDED
