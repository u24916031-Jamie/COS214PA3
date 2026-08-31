#ifndef GOLFHOLE_H
#define GOLFHOLE_H

#include "EventUnit.h"
#include "Player.h"
#include <vector>
#include "PlayerTent.h"


class GolfHole : public EventUnit {

private:
	std::vector<Player*> players;
	int holeNumber;
	int par;

	PlayerTent* tent;
public:
	GolfHole() = delete;
	/**
	 * @brief Constructor for GolfHole
	 * */
	GolfHole(int holeNum, int par, int capacity) : EventUnit(capacity, EventUnitType::GolfHoleUnit) {
		players.reserve(capacity);
		this->holeNumber = holeNum;
		this->par = par;
	};

	int getPar() const {
		return par;
	}
	int getHoleNumber()const {
		return holeNumber;
	}


	virtual void open() {
		status = EventStatus::OPENED;
	};

	virtual void close() {
		status = EventStatus::CLOSED;

	};

	void addPlayer(Player* player) {
		for (int i = 0;i <(int) players.size();i++) {
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
	void SetPlayerTent(PlayerTent* tent) {
		this->tent = tent;
	}

	void HandleNotification(Notifications notif);
	/**
 * @brief Destructor
 * */
	virtual ~GolfHole();



};

#endif
