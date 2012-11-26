#ifndef LIVING_H_INCLUDED
#define LIVING_H_INCLUDED

class Living {
		protected:
			double life;
			double speed;
			double damages;

		public:
			Living();
			Living(const Living &);
			Living();
			~Living();
};

#endif // LIVING_H_INCLUDED
