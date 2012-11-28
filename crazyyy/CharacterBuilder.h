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
				Color* green = new Color(73, 115, 88);
				Character* character = new Character(0, 1, 0, 1, 1, green);

 				return character;
			};
};

#endif // CHARACTERBUILDER_H_INCLUDED
