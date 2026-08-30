#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Observer.h"
#include "EventUnit.h"
#include "PlayerState.h"
#include <iostream>
#include <string>
#include <sstream>
class PlayerObserver;

/**
* @brief Scoreboard class which displays the current tournament standings
*/
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

	/**
	* @brief Registers PlayerObserver as subject
	*@param playerObserver Weak pointer to PlayerObserver which acts as subject
	*/
	void registerPlayerObserver(PlayerObserver* playerObserver) {
		this->playerObserver = playerObserver;
	}

	/**
	* @brief Deregisters PlayerObserver as subject
	*@param playerObserver Weak pointer to PlayerObserver to be removed as subject
	*/
	void deregisterPlayerObserver(PlayerObserver* playerObserver) {
		this->playerObserver = nullptr;
	}
	/**
		* @brief Updates player scores
		*/
	void update() {
		playerScores = playerObserver->getState();
	}

	/**
		* @brief Prints out current tournament standings
		*/
	std::string printScores() {
		std::stringstream ss;
		for (auto score : playerScores) {
			ss << score.name << ": " << score.score << " Through: " << score.holesPlayed << '\n';
		}
		return ss.str();
	}



};

#endif
