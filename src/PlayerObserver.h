#ifndef PLAYEROBSERVER_H
#define PLAYEROBSERVER_H

#include "Observer.h"
#include "Subject.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include "PlayerState.h"
class Player;
class Scoreboard;


class PlayerObserver : public Observer, public Subject {
protected:
	std::vector<PlayerState> playerStates;
	std::vector < Player*> players;

	std::vector<Scoreboard*> scoreboards;


public:
	void sort();

	virtual ~PlayerObserver();
	void registerPlayer(Player* player);
	void deregisterPlayer(Player* player);

	void attach(Scoreboard* observer);


	void detach(Scoreboard* observer);


	void update();

	std::vector<PlayerState> getState();

};

#endif