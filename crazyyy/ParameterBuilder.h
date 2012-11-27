#ifndef PARAMETERBUILDER_H_INCLUDED
#define PARAMETERBUILDER_H_INCLUDED

class ParameterBuilder {
		protected:
			int difficulty;
			double height;
			double width;

		public:
			ParameterBuilder();
			ParameterBuilder(const ParameterBuilder &);
			ParameterBuilder();
			~ParameterBuilder();
};

#endif // PARAMETERBUILDER_H_INCLUDED
