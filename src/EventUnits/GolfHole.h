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
	virtual void SetPlayerTent(PlayerTent* tent) {
		this->tent = tent;
	}

	virtual void HandleNotification(Notifications notif) {
		switch (notif) {
		case(PAUSE):
		{
			for (int i = 0;i < players.size();i++) {
				tent->addPlayer(players[i]);
				players[i]->leaveHole();
			}
			players.clear();
			this->setStatus(PAUSED);
		}
		case(RESUME):
		{
			players = tent->getPlayersOnHole(holeNumber);
			this->setStatus(EventStatus::OPEN);
		}

		}
	}
	/**
 * @brief Destructor
 * */
	virtual ~GolfHole() {};



};

#endif
