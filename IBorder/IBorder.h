
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
		virtual void drawBorder(int, int, int, Graphics&){};

		//D'tors
		virtual ~IBorder() = 0;

};
