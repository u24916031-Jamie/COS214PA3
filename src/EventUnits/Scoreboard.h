#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Observer.h"
#include "EventUnit.h"
#include "PlayerState.h"
#include <iostream>
#include <string>
#include <sstream>
class PlayerObserver;
class Scoreboard : public EventUnit, public Observer {
private:
	PlayerObserver* playerObserver;
	std::vector<PlayerState> playerScores;
public:
	/**
	 * @brief Constructor for Scoreboard
	 * */
	Scoreboard() : EventUnit(0, Other) {};

	/**
 * @brief Destructor
 * */
	virtual ~Scoreboard() {
		playerObserver->detach(this);

	};


	void registerPlayerObserver(PlayerObserver* playerObserver) {
		this->playerObserver = playerObserver;
	}
	void deregisterPlayerObserver(PlayerObserver*) {
		this->playerObserver = nullptr;
	}

	void update() {
		playerScores = playerObserver->getState();
	}


	std::string printScores() {
		std::stringstream ss;
		for (auto score : playerScores) {
			ss << score.name << ": " << score.score << " Through: " << score.holesPlayed << '\n';
		}
		return ss.str();
	}



};

#endif
