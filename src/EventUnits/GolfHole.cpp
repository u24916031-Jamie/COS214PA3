#include "GolfHole.h"
#include "Player.h"


void GolfHole::HandleNotification(Notifications notif) {
	switch (notif) {
	case(PAUSE):
	{
		for (std::size_t i = 0;i < players.size();i++) {
			tent->addPlayer(players[i]);
			players[i]->leaveHole();
		}
		players.clear();
		this->setStatus(PAUSED);
		break;
	}
	case(RESUME):
	{
		players = tent->getPlayersOnHole(holeNumber);
		this->setStatus(EventStatus::OPENED);
		break;
	}
	default:
	{
		break;
	}

	}
}


GolfHole::~GolfHole() {};