#pragma once


#include <windows.h>
#include <iostream>



using namespace std;
class IControl;

class IColor {

	public:

		// methods
		virtual bool SetColor(IControl* control) = 0;

		//D'tors
		virtual ~IColor() {};

};
