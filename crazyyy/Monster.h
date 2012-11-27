#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

class Monster {
		protected:
			int level;
			int points;

		public:
			Monster();
			Monster(const Monster &);
			Monster();
			~Monster();
};

#endif // MONSTER_H_INCLUDED
