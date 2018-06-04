
#include <windows.h>
#include <iostream>

#pragma once

using namespace std;


class IBorder {

	public:

		// methods
		void DrawBorder();

		//D'tors
		virtual ~IBorder() {};

};
