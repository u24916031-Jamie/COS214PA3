#ifndef PLAYERTENT_H
#define PLAYERTENT_H


#include "EventUnit.h"
#include <vector>
#include "Player.h"

class PlayerTent : public EventUnit {
private:
	std::vector<Player*> players;

public:
	PlayerTent() = delete;
	PlayerTent(int capacity) :EventUnit(capacity, Other) {};


	void addPlayer(Player* player) {
		for (int i = 0;i < players.size();i++) {
			if (players[i] == player) {
				return;
			}
		}
		players.push_back(player);
	}
	void removePlayer(Player* player) {
		std::vector<Player*>::iterator it;
		for (it = players.begin();it != players.end();it++) {
			if (players[it - players.begin()] == player) {
				players.erase(it);

				return;
			}
		}
	}
	std::vector<Player*> getPlayersOnHole(int hole) {
		std::vector<Player*> retPlayers;

		for (int i = 0;i < players.size();i++) {
			if (players[i]->getState().holesPlayed == hole) {
				retPlayers.push_back(players[i]);
			}
		}
		for (auto player : players) {
			removePlayer(player);
		}


		return retPlayers;
	}
};

#endif
