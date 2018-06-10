#pragma once

#include "../IObserver/IObservable.h"

using namespace std;

class IObservable;

class IListener {

	public:

		// methods
		virtual void action(IObservable* observable) = 0;

		//D'tors
		virtual ~IListener() {};

};