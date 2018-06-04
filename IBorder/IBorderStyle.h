
#include <windows.h>
#include <iostream>
#include "IBorder.h"

#pragma once

using namespace std;


class IBorderStyle : public IBorder {

	private:
		char _topLeft;
		char _topRight;
		char _buttomLeft;
		char _buttomRight;
		char _horizontalLine;
		char _verticalLine;

	public:

		// methods

		//D'tors
		virtual ~IBorderStyle() {};

};
