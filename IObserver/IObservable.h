#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "../IListener/IListener.h"


using namespace std;

class IListener;

class IObservable {

	protected:
		// Atrributes
		vector<IListener*> listeners_;

	public:

		// methods
         void notify();
		 void add(IListener* listener);

		//D'tors
		virtual ~IObservable() = 0;

};