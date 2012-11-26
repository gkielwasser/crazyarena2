#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class Game {
		protected:
			double score;
			double duration;

		public:
			Game();
			Game(const Game &);
			Game();
			~Game();

			void getCharacter() {

			};

			void getMonsters() {

			};
};

#endif // GAME_H_INCLUDED
