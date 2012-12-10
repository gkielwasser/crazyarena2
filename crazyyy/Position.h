#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

class Position {
protected:
	float x;
	float y;
	float z;

public:
	Position();
	Position(const Position &);

	Position(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}


	~Position();

	float getX() {
		return x;
	}

	float getY() {
		return y;
	}

	float getZ() {
		return z;
	}

	void setX(float x) {
		this->x = x;
	}

	void setY(float y) {
		this->y = y;
	}

	void setZ(float z) {
		this->z = z;
	}
};

#endif // POSITION_H_INCLUDED
