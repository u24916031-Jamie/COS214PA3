#include "GolfHole.h"
#include "Player.h"


void GolfHole::HandleNotification(Notifications notif) {
	switch (notif) {
	case(PAUSE):
	{
		std::vector<Player*> onHole = players;
		for (std::size_t i = 0;i < onHole.size();i++)
		{
			tent->addPlayer(onHole[i]);
			onHole[i]->leaveHole();
		}
		players.clear();
		this->setStatus(PAUSED);
		break;
	}
	case(RESUME):
	{
		std::vector<Player*> returning = tent->getPlayersOnHole(holeNumber);
		for (std::size_t i = 0;i < returning.size();i++)
		{
			returning[i]->beginHole(this);
		}
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
