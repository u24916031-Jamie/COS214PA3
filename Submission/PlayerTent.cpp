#include "PlayerTent.h"
#include "Player.h"


std::vector<Player*> PlayerTent::getPlayersOnHole(int hole) {
	std::vector<Player*> retPlayers;

	std::vector<Player*> staying;

	for (std::size_t i = 0;i < players.size();i++) {
		if (players[i]->getState().holesPlayed == hole) {
			retPlayers.push_back(players[i]);
		}
		else
		{
			staying.push_back(players[i]);
		}
	}
	players = staying;


	return retPlayers;
}
