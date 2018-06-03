
#include <windows.h>
#include <iostream>
#include "IColor.h"
#include "IControl.h"

#pragma once

using namespace std;


class ITextColor : public IColor {

	private:
		// Atrributes
		DWORD _textColor;

	public:

		//D'tors
		virtual ~ITextColor() {};

};
