#ifndef GAMEDIRECTOR_H_INCLUDED
#define GAMEDIRECTOR_H_INCLUDED

class GameDirector {
		public:
			GameDirector();
			GameDirector(const GameDirector &);
			GameDirector();
			~GameDirector();

			void createGame() {
				// appeller le mapbuilder
			}
};

#endif // GAMEDIRECTOR_H_INCLUDED
