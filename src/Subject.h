#ifndef SUBJEECT_H
#define SUBJEECT_H

#include <vector>
#include "Observer.h"


class Subject {
private:
	std::vector<Observer*> observerList;

public:
	virtual void notify() {
		for (size_t i = 0;i < observerList.size();i++) {
			observerList[i]->update();
		}
	}


	void attach(Observer* observer) {
		for (size_t i = 0;i < observerList.size();i++) {
			if (observerList[i] == observer) {
				return;
			}
		}
		observerList.push_back(observer);
	}
	void detach(Observer* observer) {
		for (size_t i = 0;i < observerList.size();i++) {
			if (observerList[i] == observer) {
				std::vector<Observer*>::iterator it;
				it += i;
				observerList.erase(it);
				return;
			}
		}
	}


};

#endif
