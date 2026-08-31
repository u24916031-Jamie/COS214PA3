#ifndef PLAYER_H
#define PLAYER_H

#include "Subject.h"
#include <string>
#include "PlayerObserver.h"

#include "PlayerState.h"

class GolfHole;

class Player :public Subject {
private:
	PlayerState state;
	GolfHole* currentHole;

public:
	Player() = delete;
	/**
	 * @brief Constructor for Player
	 * */
	Player(std::string name) : Subject() {
		state.name = name;
		currentHole=nullptr;
	};

	/**
 * @brief Destructor
 * */
	virtual ~Player() {

		for (size_t i = 0;i < observerList.size();i++) {
			if (PlayerObserver* po = dynamic_cast<PlayerObserver*>(observerList[i])) {

				po->deregisterPlayer(this);
			}


		}
		observerList.clear();
	};

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
		if(observer==nullptr)
		{
			return;
		}
		for (size_t i = 0;i < observerList.size();i++) {
			if (observerList[i] == observer) {
				// std::vector<Observer*>::iterator it;
				// it += i;
				observer->deregisterPlayer(this);
				observerList.erase(observerList.begin()+i);
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


	void finishHole(int score);

	void beginHole(GolfHole* hole);
	void leaveHole();

};

#endif
