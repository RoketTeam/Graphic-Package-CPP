
# pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include "IControl.h"

using namespace std;


class ListItem : public Control {

	private:
		// Atrributes
		Label descriptionLabel_;
		short lineLengh_;
		bool isChecked_;
		bool isFocused_;


	// Methods
		void MarkAsChoose();
		void MarkAsUnchoose();
		bool SetColor(DWORD color);

	public:
		// C'tors
		ListItem(short positionX, short positionY, string description);

		// methods
		bool focus();
		bool unfocus();
		bool isFocus() { return _isFocused; }
		bool isHover(); // need redesign
		short getLineLengh() { return _lineLengh; }

		//D'tors
		~ListItem();

};