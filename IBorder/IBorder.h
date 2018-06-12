
#include <windows.h>
#include "../Control/Control.h"
#include <iostream>

#pragma once

using namespace std;


class IBorder {

	private:
		char topCorner;
		char horizontalLine;
		char topRightCorner;
		char verticalLine;
		char bottomLeftCorner;
		char bottomRightCorner;

	public:

		// methods
		void drawBorder(Control*);

		//D'tors
		virtual ~IBorder() = 0;

};
