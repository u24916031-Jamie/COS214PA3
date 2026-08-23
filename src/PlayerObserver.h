#ifndef PLAYEROBSERVER_H
#define PLAYEROBSERVER_H

#include "Observer.h"
#include "Subject.h"
#include "Player.h"
#include <vector>

class PlayerObserver : public Observer, public Subject {
private:

	PlayerState playerState;
	Player* player;

public:
	void registerPlayer(Player* player) {
		player = player;
	}
	void deregisterPlayer() {
		player = nullptr;
	}

	void update() {
		playerState = player->getState();
	}
	PlayerState getState() {
		return playerState;
	}


};

#endif