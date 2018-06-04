
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "IListener.h"

#pragma once

using namespace std;


class IObservable {

	private:
		// Atrributes
		vector<IListener> _listeners;

	public:

		// methods
		 void Notify();
		 void Add(IListener* listener);

		//D'tors
		virtual ~IObservable() {};

};