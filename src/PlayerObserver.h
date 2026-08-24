#ifndef PLAYEROBSERVER_H
#define PLAYEROBSERVER_H

#include "Observer.h"
#include "Subject.h"
#include "Player.h"
#include <vector>
#include "Scoreboard.h"
#include <algorithm>
#include <numeric>

class PlayerObserver : public Observer, public Subject {
protected:
	std::vector<PlayerState> playerStates;
	std::vector < Player*> players;

	std::vector<Scoreboard*> scoreboards;


public:
	void sort() {

		int n = players.size();

		// 1. Create a vector of indices [0, 1, 2, ..., n-1]
		std::vector<int> indices(n);
		std::iota(indices.begin(), indices.end(), 0);

		// 2. Sort indices based on the values in the 'keys' array
		std::sort(indices.begin(), indices.end(), [&](int i, int j) {
			return playerStates[i].score < playerStates[j].score;
			});

		// 3. Reorder the original arrays using the sorted indices
		std::vector<PlayerState> sortedplayerStates;
		std::vector < Player*> sortedplayers;
		for (int i = 0; i < n; ++i) {
			sortedplayerStates[i] = playerStates[indices[i]];
			sortedplayers[i] = players[indices[i]];
		}

		playerStates = sortedplayerStates;
		players = sortedplayers;

	}

	virtual ~PlayerObserver() {
		for (int i = 0;i < players.size();i++) {
			players[i]->detach(this);
		}
	}
	void registerPlayer(Player* player) {
		for (int i = 0;i < players.size();i++) {
			if (players[i] == player) {
				return;
			}
		}
		players.push_back(player);
		playerStates.push_back(player->getState());
	}
	void deregisterPlayer(Player* player) {
		for (int i = 0;i < players.size();i++) {
			if (players[i] == player) {
				std::vector<Player*>::iterator playerIt;
				std::vector<PlayerState>::iterator statesIt;
				playerIt += i;
				statesIt += i;
				players.erase(playerIt);
				playerStates.erase(statesIt);
				return;
			}
		}
	}

	void attach(Scoreboard* observer) {
		for (size_t i = 0;i < observerList.size();i++) {
			if (observerList[i] == observer) {
				return;
			}
		}
		observerList.push_back(observer);
		observer->registerPlayerObserver(this);





	}


	void detach(Scoreboard* observer) {
		for (size_t i = 0;i < observerList.size();i++) {
			if (observerList[i] == observer) {
				std::vector<Observer*>::iterator it;
				it += i;
				observer->deregisterPlayerObserver(this);
				observerList.erase(it);
				return;
			}
		}
	}


	void update() {
		for (int i = 0;i < players.size();i++) {
			playerStates[i] = players[i]->getState();
		}
	}

	std::vector<PlayerState> getState() {
		return playerStates;
	}

};

#endif