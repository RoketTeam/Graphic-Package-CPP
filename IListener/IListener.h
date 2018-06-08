#pragma once

using namespace std;


class IListener {

	public:

		// methods
		virtual void action() = 0;

		//D'tors
		virtual ~IListener() {};

};