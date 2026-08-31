//Include format: #include "testing.h"


#include "GolfTournament.h"
#include "GolfCourse.h"
#include "GolfHole.h"
#include "PlayerTent.h"
#include "FoodStall.h"
#include "Scoreboard.h"
#include "WeatherMeter.h"
#include "WeatherObserver.h"
#include "Player.h"
#include "PlayerObserver.h"


#include <iostream>

/**
 * @brief The objects that appear as lifelines in the sequence diagrams.
 */
struct EventFlow
{
	EventComponent* tournament;
	GolfCourse* course;
	GolfHole* hole1;
	PlayerTent* tent;
	FoodStall* foodStall;
	Scoreboard* scoreboard1;
	Scoreboard* scoreboard2;
	WeatherMeter* weatherMeter;
	WeatherObserver* weatherObs;
	Player* scottie;
	PlayerObserver* manager;
};

/**
 * @brief SD1 - Building and registering part of the event.
 * @param e The objects shared by all four scenarios.
 */
void SD1(EventFlow& e)
{
	std::cout << "\n===== SD1: Building and registering part of the event =====\n";

	e.tournament = new GolfTournament();
	e.course = new GolfCourse();
	e.hole1 = new GolfHole(1, 4, 4);
	e.tent = new PlayerTent(20);
	e.foodStall = new FoodStall(30);
	e.scoreboard1 = new Scoreboard();

	e.course->addComponent(e.hole1);
	e.course->addComponent(e.tent);
	e.course->addComponent(e.foodStall);
	e.course->addComponent(e.scoreboard1);
	e.tournament->addComponent(e.course);

	e.course->SetPlayerTent(e.tent);

	e.manager = new PlayerObserver();
	e.scottie = new Player("Scottie Scheffler");

	e.manager->attach(e.scoreboard1);
	e.scottie->attach(e.manager);

	e.weatherMeter = new WeatherMeter(0);
	e.course->addComponent(e.weatherMeter);
	e.weatherObs = new WeatherObserver();
	e.weatherMeter->attach(e.weatherObs);
	e.weatherObs->setRoot(e.tournament);

	e.scoreboard2 = nullptr;

	e.tournament->open();
	std::cout << "Tournament capacity: " << e.tournament->getCapacity() << '\n';
}

/**
 * @brief SD2 - Cascading event notification (pull).
 * @param e The objects shared by all four scenarios.
 */
void SD2(EventFlow& e)
{
	std::cout << "\n===== SD2: Cascading event notification (pull) =====\n";

	e.scottie->beginHole(e.hole1);
	e.scottie->finishHole(-1);

	std::cout << e.scoreboard1->printScores();
}

/**
 * @brief SD3 - Conditional event response and Composite behaviour.
 * @param e The objects shared by all four scenarios.
 */
void SD3(EventFlow& e)
{
	std::cout << "\n===== SD3: Conditional event response (THUNDER, then RAIN) =====\n";

	e.weatherMeter->setWeather(THUNDER);
	std::cout << "hole1 status after THUNDER: " << e.hole1->reportStatus() << " (2 = PAUSED)\n";

	e.weatherMeter->setWeather(RAIN);
	std::cout << "hole1 status after RAIN:    " << e.hole1->reportStatus() << " (unchanged)\n";
}

/**
 * @brief SD4 - Storm delay, tent shelter, scoreboard swap and resume.
 * @param e The objects shared by all four scenarios.
 */
void SD4(EventFlow& e)
{
	std::cout << "\n===== SD4: Scoreboard swap during the delay, then resume =====\n";

	e.course->removeComponent(e.scoreboard1);
	delete e.scoreboard1;
	e.scoreboard1 = nullptr;

	e.scoreboard2 = new Scoreboard();
	e.course->addComponent(e.scoreboard2);
	e.manager->attach(e.scoreboard2);

	e.weatherMeter->setWeather(CLEAR);
	std::cout << "hole1 status after CLEAR:   " << e.hole1->reportStatus() << " (0 = OPENED)\n";

	e.scottie->finishHole(-2);

	std::cout << e.scoreboard2->printScores();
}

/**
 * @brief Detaches the observers and deletes the root, which releases the tree.
 * @param e The objects shared by all four scenarios.
 */
void shutdown(EventFlow& e)
{
	std::cout << "\n===== Shutdown =====\n";

	e.tournament->close();
	e.weatherMeter->detach(e.weatherObs);
	e.scottie->detach(e.manager);

	delete e.tournament;
	delete e.manager;
	delete e.weatherObs;
	delete e.scottie;

	std::cout << "All components released.\n";
}

int main()
{

	EventFlow e;

	SD1(e);
	SD2(e);
	SD3(e);
	SD4(e);

	shutdown(e);

	

	return 0;
}
