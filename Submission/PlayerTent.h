#ifndef PLAYERTENT_H
#define PLAYERTENT_H


#include "EventUnit.h"
#include <vector>
class Player;



/**
* @brief Area for players to rest between holes and before/after the round
*/
class PlayerTent : public EventUnit {
private:
	std::vector<Player*> players;

public:
	PlayerTent() = delete;
	/**
* @brief PlayerTent constructor
* @param capacity Maximum capacity of the tent
*/
	PlayerTent(int capacity) :EventUnit(capacity, Other) {};

	/**
* @brief PlayerTent destructor
*/
	virtual ~PlayerTent() {};


	/**
* @brief Adds a player to the tent
* @param player Weak pointer to player to be added to tent
*/
	void addPlayer(Player* player) {
		for (int i = 0;i <(int) players.size();i++) {
			if (players[i] == player) {
				return;
			}
		}
		players.push_back(player);
	}

	/**
* @brief Removes a player from the tent
* @param player Weak pointer to player to be removed from tent
*/
	void removePlayer(Player* player) {
		std::vector<Player*>::iterator it;
		for (it = players.begin();it != players.end();it++) {
			if (players[it - players.begin()] == player) {
				players.erase(it);

				return;
			}
		}
	}
	std::vector<Player*> getPlayersOnHole(int hole);
};

#endif
