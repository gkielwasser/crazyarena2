#ifndef MAPBUILDER_H_INCLUDED
#define MAPBUILDER_H_INCLUDED

class MapBuilder {
		protected:
			double life;
			double speed;
			double damages;

		public:
			MapBuilder();
			MapBuilder(const MapBuilder &);
			MapBuilder();
			~MapBuilder();
};

#endif // MAPBUILDER_H_INCLUDED
