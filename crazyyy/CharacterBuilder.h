#ifndef CHARACTERBUILDER_H_INCLUDED
#define CHARACTERBUILDER_H_INCLUDED
#include "Character.h"

using namespace std;

class CharacterBuilder {
		public:
			CharacterBuilder(){};
			CharacterBuilder(const CharacterBuilder &);
			~CharacterBuilder();

			Character* createCharacter() {
				Color* red = new Color(255, 0, 0);
				Character* character = new Character(0, 1, 0, 1, 1, red);

 				return character;
			};
};

#endif // CHARACTERBUILDER_H_INCLUDED
