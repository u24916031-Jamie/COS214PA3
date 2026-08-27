#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Observer.h"
#include "EventUnit.h"
#include "PlayerObserver.h"

class Scoreboard : public EventUnit, public Observer {
	friend PlayerObserver;
private:
	PlayerObserver* playerObserver;
	std::vector<PlayerState> playerScores;
public:
	Scoreboard() = delete;
	/**
	 * @brief Constructor for Scoreboard
	 * */
	Scoreboard(int capacity) : EventUnit(capacity, Other) {};

	/**
 * @brief Destructor
 * */
	virtual ~Scoreboard() {
		playerObserver->detach(this);

	};


	void registerPlayerObserver(PlayerObserver* playerObserver) {
		this->playerObserver = playerObserver;
	}
	void deregisterPlayerObserver(PlayerObserver* playerObserver) {
		this->playerObserver = nullptr;
	}

	void update() {
		playerScores = playerObserver->getState();
	}
};

#endif
