#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <iostream>
#include <sstream>

using namespace std;

class Timer {
public:
	Uint32 startTime;

	Timer() {
		startTime = SDL_GetTicks();
	};

	~Timer();

	double getTime() {
		return (SDL_GetTicks() - startTime) / 1000;
	};

	string getString() {
		ostringstream result;

		double time = this->getTime();
		int minutes = (int)(time / 60);
		int seconds = (int)((int)time % 60);

		if (minutes < 10) {
			result << "0" << minutes;
		}
		else {
			result << minutes;
		}

		result << ":";

		if (seconds < 10) {
			result << "0" << seconds;
		}
		else {
			result << seconds;
		}

		return result.str();
	};

	const char* getChar() {
		string s = this->getString();
		return s.c_str();
	}

	void draw() {
		char strMsg[15] = {0};
		const char* strMsgArg = this->getChar();

		glPushMatrix();
			glLoadIdentity();
			glRasterPos3f(-0.4f,-0.4f,-1.);
			sprintf (strMsg, "Time : %s", strMsgArg);

			for (unsigned int i = 0; i < strlen(strMsg); i++) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *(strMsg + i));
			}
		glPopMatrix();
	};
};

#endif // TIMER_H_INCLUDED
