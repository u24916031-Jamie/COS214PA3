#ifndef PLAYEROBSERVERMANAGER_H
#define PLAYEROBSERVERMANAGER_H

#include "Observer.h"
#include "Subject.h"
#include "Player.h"
#include "PlayerObserver.h"
#include <vector>
#include "Scoreboard.h"

class PlayerObserverManager : public Observer, public Subject {
protected:
	std::vector<PlayerState> playerStates;
	std::vector < PlayerObserver*> players;

	std::vector<Scoreboard*> scoreboards;


public:
	void registerManager(Player* player) {
		player = player;
	}


	void attach(Scoreboard* observer) {
		for (size_t i = 0;i < observerList.size();i++) {
			if (observerList[i] == observer) {
				return;
			}
		}
		observerList.push_back(observer);
		observer->registerPlayer(this);

	}


	void detach(Scoreboard* observer) {
		for (size_t i = 0;i < observerList.size();i++) {
			if (observerList[i] == observer) {
				std::vector<Observer*>::iterator it;
				it += i;
				observer->deregisterPlayer();
				observerList.erase(it);
				return;
			}
		}
	}
	void deregisterPlayer() {
		player = nullptr;
	}

	void update() {
		playerState = player->getState();
	}

};

#endif