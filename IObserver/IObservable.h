
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "../IListener/IListener.h"

#pragma once

using namespace std;


class IObservable {

	protected:
		// Atrributes
		vector<IListener*> listeners_;

	public:

		// methods
		 virtual void notify() = 0;
		 void add(IListener* listener);

		//D'tors
		virtual ~IObservable() {};

};