#pragma once

#include <windows.h>
#include <iostream>
#include "IColor.h"
#include "IControl.h"


using namespace std;


class IBGColor : public IColor {

	private:
		// Atrributes
		DWORD _backGroundColor;

	public:

		//D'tors
		virtual ~IBGColor() {};

};

