#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

class Color {
	private:
		unsigned char red;
		unsigned char green;
		unsigned char blue;
	public:
		Color(){};
		Color(const Color &);

		Color(unsigned char red, unsigned char green, unsigned char blue){
			this->red = red;
			this->green = green;
			this->blue = blue;
		};

		~Color();

		unsigned char getBlue()
		{
			return blue;
		}

		unsigned char getGreen()
		{
			return green;
		}

		unsigned char getRed()
		{
			return red;
		}
};





#endif // COLOR_H_INCLUDED
