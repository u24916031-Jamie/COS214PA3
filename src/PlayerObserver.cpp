#include "PlayerObserver.h"
#include "Player.h"
#include "Scoreboard.h"

void PlayerObserver::sort() {

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

PlayerObserver::~PlayerObserver() {
	for (std::size_t i = 0;i < players.size();i++) {
		players[i]->detach(this);
	}
	for (std::size_t i = 0;i < scoreboards.size();i++) {
		scoreboards[i]->deregisterPlayerObserver(this);
	}


}

void PlayerObserver::registerPlayer(Player* player) {
	for (std::size_t i = 0;i < players.size();i++) {
		if (players[i] == player) {
			return;
		}
	}
	players.push_back(player);
	playerStates.push_back(player->getState());
}
void PlayerObserver::deregisterPlayer(Player* player) {
	for (std::size_t i = 0;i < players.size();i++) {
		if (players[i] == player) {
			// std::vector<Player*>::iterator playerIt;
			// std::vector<PlayerState>::iterator statesIt;
			// playerIt += i;
			// statesIt += i;
			players.erase(players.begin()+i);
			playerStates.erase(playerStates.begin()+i);
			return;
		}
	}
}

void PlayerObserver::attach(Scoreboard* observer) {
	for (std::size_t i = 0;i < observerList.size();i++) {
		if (observerList[i] == observer) {
			return;
		}
	}
	observerList.push_back(observer);
	observer->registerPlayerObserver(this);





}


void PlayerObserver::detach(Scoreboard* observer) {
	if(observer==nullptr)
	{
		return;
	}
	if(observerList.empty())
	{
		return;
	}
	for (size_t i = 0;i < observerList.size();i++) {
		if (observerList.at(i) == observer) {
			//std::vector<Observer*>::iterator it;
			//it += i;
			//observer->deregisterPlayerObserver(this);
			observerList.erase(observerList.begin()+i);
			return;
		}
	}
}


void PlayerObserver::update() {
	for (int i = 0;i <(int) players.size();i++) {
		playerStates[i] = players[i]->getState();
	}
	notify();
}

std::vector<PlayerState> PlayerObserver::getState() {
	return playerStates;
}