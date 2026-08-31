#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <string>

struct PlayerState {
	std::string name;
	int holesPlayed = 0;
	int score = 0;
	int par = 0;

};


#endif