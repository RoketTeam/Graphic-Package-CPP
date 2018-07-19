
#include <windows.h>
#include <iostream>
#include "IBorder.h"

#pragma once

using namespace std;


class IBorderStyle : public IBorder {

	protected:
		char topCorner;
		char horizontalLine;
		char topRightCorner;
		char verticalLine;
		char bottomLeftCorner;
		char bottomRightCorner;

	public:

		IBorderStyle(char, char, char, char, char, char);
		// methods
		virtual void drawBorder(int top, int left, int length, Graphics& g, int amount);


		//D'tors
		virtual ~IBorderStyle() {};

};
