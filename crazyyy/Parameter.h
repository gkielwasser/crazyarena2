#ifndef PARAMETER_H_INCLUDED
#define PARAMETER_H_INCLUDED

class Parameter {
		protected:
			int difficulty;
			double height;
			double width;

		public:
			Parameter();
			Parameter(const Parameter &);
			Parameter();
			~Parameter();
};

#endif // PARAMETER_H_INCLUDED
