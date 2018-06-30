
# pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include "IControl.h"

using namespace std;


class ListItem : public Control {

	private:
		// Atrributes
		Label description_label_;
		short line_lengh_;
		bool is_checked_;
		bool is_focused_;


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
		bool is_focus() { return _isFocused; }
		bool is_hover(); // need redesign
	    void draw(Graphics& g, int x, int y, size_t z);

	    short get_line_lengh() { return line_lengh_; }

		//D'tors
		~ListItem();

};