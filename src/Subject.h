#ifndef SUBJEECT_H
#define SUBJEECT_H

#include <vector>
#include "Observer.h"
#include <iostream>

class Subject {
protected:
	std::vector<Observer*> observerList;

public:
	virtual void notify() {
		for (std::size_t i = 0;i < observerList.size();i++) {
			std::cout << "Updating observer: " << i << '\n';
			observerList[i]->update();
		}
	}





};

#endif
