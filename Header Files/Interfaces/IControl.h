#pragma once


#include <windows.h>
#include <iostream>
#include <string>
#include "IBorder.h"
#include "IColor.h"
#include "IBGColor.h"
#include "ITextColor.h"

using namespace std;


class IControl {

	private:
		// Atrributes
	
		COORD _size;
		COORD _position;
		IBorder* _border;
		IBGColor* _backGroundColor;
		ITextColor* _textColor;

	public:

		// methods
		 void Draw();
		 void HandleEvent(INPUT_RECORD inputRecord) ;
		 void ChangeColors(IBGColor* backGroundColor, ITextColor* textColor);

		//D'tors
		virtual ~IControl() {};

};
