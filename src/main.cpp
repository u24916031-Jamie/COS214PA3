
//Include format: #include "testing.h"


#include "GolfTournament.h"
#include "GolfCourse.h"
#include "GolfHole.h"
#include "Player.h"
#include "PlayerObserver.h"
#include "Scoreboard.h"
int main() {




	EventComponent* tournament = new GolfTournament();

	GolfCourse* course = new GolfCourse();


	GolfHole* hole1 = new GolfHole(1, 4, 4);


	Scoreboard* scoreboard1 = new Scoreboard();


	course->addComponent(hole1);
	course->addComponent(scoreboard1);




	tournament->addComponent(course);



	Player scottie("Scottie Sheffler");
	PlayerObserver* manager = new PlayerObserver();


	scottie.attach(manager);

	scottie.beginHole(hole1);

	scottie.finishHole(-1);

	scottie.leaveHole();




	return 0;
}