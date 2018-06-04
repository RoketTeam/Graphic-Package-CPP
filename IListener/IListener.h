#pragma once

using namespace std;


class IListener {

	public:

		// methods
		virtual void Action() = 0;

		//D'tors
		virtual ~IListener() {};

};