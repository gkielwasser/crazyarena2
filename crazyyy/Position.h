#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

class Position {
		protected:
			double x;
			double y;
			double z;

		public:
			Position();
			Position(const Position &);
			Position();
			~Position();
};

#endif // POSITION_H_INCLUDED
