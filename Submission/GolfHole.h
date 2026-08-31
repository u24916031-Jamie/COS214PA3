#ifndef GOLFHOLE_H
#define GOLFHOLE_H

#include "EventUnit.h"
#include "Player.h"
#include <vector>
#include "PlayerTent.h"



/**
 *
 * @brief Golf hole that is played by player
 *
 */
class GolfHole : public EventUnit {

private:
	std::vector<Player*> players;
	int holeNumber;
	int par;

	PlayerTent* tent;
public:
	GolfHole() = delete;
	/**
	 * @brief Constructor for GolfHole
	 * */
	GolfHole(int holeNum, int par, int capacity) : EventUnit(capacity, EventUnitType::GolfHoleUnit) {
		players.reserve(capacity);
		this->holeNumber = holeNum;
		this->par = par;
	};
	/**
	 * @brief returns the par for the hole
	 *@return int par
	 */
	int getPar() const {
		return par;
	}
	/**
 * @brief returns the number of the hole
 *@return int hole number
 */
	int getHoleNumber()const {
		return holeNumber;
	}

	/**
 * @brief Sets status of golf hole to OPENED
 */
	virtual void open() {
		status = EventStatus::OPENED;
	};

	/**
* @brief Sets status of golf hole to CLOSED
*/
	virtual void close() {
		status = EventStatus::CLOSED;

	};

	/**
* @brief Adds a player to the hole
*@param player Weak pointer to player about to play this hole
*/
	void addPlayer(Player* player) {
		for (int i = 0;i <(int) players.size();i++) {
			if (players[i] == player) {
				return;
			}
		}
		players.push_back(player);
	}

	/**
* @brief Removes player from hole
*@param player Weak pointer to player playing this hole
*/
	void removePlayer(Player* player) {
		std::vector<Player*>::iterator it;
		for (it = players.begin();it != players.end();it++) {
			if (players[it - players.begin()] == player) {
				players.erase(it);

				return;
			}
		}
	}
	/**
* @brief Sets the PlayerTent
*@param player Weak pointer to PlayerTent
*/
	void SetPlayerTent(PlayerTent* tent) {
		this->tent = tent;
	}
	/**
* @brief Handles all notifications
*@param notif Notification
*/
	void HandleNotification(Notifications notif);
	/**
 * @brief Destructor
 * */
	virtual ~GolfHole();



};

#endif
