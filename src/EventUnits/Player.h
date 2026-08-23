#ifndef PLAYER_H
#define PLAYER_H

#include "EventUnit.h"
#include "Subject.h"
#include <string>
#include "PlayerObserver.h"

struct PlayerState {
	std::string name;
	int holesPlayed = 0;
	int score = 0;
};

class Player : public EventUnit, public Subject {
private:
	PlayerState state;

public:
	Player() = delete;
	/**
	 * @brief Constructor for Player
	 * */
	Player(std::string name) : EventUnit() {
		state.name = name;
	};

	/**
 * @brief Destructor
 * */
	virtual ~Player() {};

	void attach(PlayerObserver* observer) {
		for (size_t i = 0;i < observerList.size();i++) {
			if (observerList[i] == observer) {
				return;
			}
		}
		observerList.push_back(observer);
		observer->registerPlayer(this);

	}


	void detach(PlayerObserver* observer) {
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

	PlayerState getState() {
		return state;
	}
	void setState(int holesPlayed, int score) {
		state.holesPlayed = holesPlayed;
		state.score = score;
	}

	void setState(PlayerState state) {
		this->state = state;
	}


	void finishHole(int score) {
		if (state.holesPlayed == 18) {
			return;
		}
		state.score += score;
		state.holesPlayed++;
	}


};

#endif
