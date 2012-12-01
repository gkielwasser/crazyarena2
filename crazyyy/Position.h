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

			Position(double x, double y, double z) {
				this->x = x;
				this->y = y;
				this->z = z;
			};

			~Position();

			double getX() const;
			double getY() const;
			double getZ() const;
			void setX(double x);
			void setY(double y);
			void setZ(double z);
};

double Position::getX() const
{
    return x;
}

double Position::getY() const
{
    return y;
}

double Position::getZ() const
{
    return z;
}

void Position::setX(double x)
{
    this->x = x;
}

void Position::setY(double y)
{
    this->y = y;
}

void Position::setZ(double z)
{
    this->z = z;
}



#endif // POSITION_H_INCLUDED
