
#include <windows.h>
#include "../Graphics/Graphics.h"
#include <iostream>

#pragma once

using namespace std;

class IBorder {

	private:


	public:

		// methods
		IBorder(){};
		virtual void drawBorder(int top, int left, int length, Graphics& g, int amount = 3){};

		//D'tors
		virtual ~IBorder() = 0;

};
