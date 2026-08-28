#include "Player.h"
#include <iostream>
#include "GolfHole.h"
void Player::finishHole(int score) {

	if (state.holesPlayed == 18) {
		return;
	}
	state.score += score;
	state.par += currentHole->getPar();
	state.holesPlayed++;
	std::cout << "Player " << state.name << " Finished hole: " << state.holesPlayed << '\n';
	notify();
}

void Player::beginHole(GolfHole* hole) {
	currentHole = hole;
	hole->addPlayer(this);
}
void Player::leaveHole() {
	currentHole->removePlayer(this);
	currentHole = nullptr;

}