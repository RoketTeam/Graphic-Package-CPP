
# pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include "../Control/Control.h"
#include "../Label/Label.h"

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
		ListItem(string description);
		ListItem(short positionX, short positionY, string description);

		// Setters & Getters
		void set_left(short left);
		void set_top(short top);

		// methods
		bool focus();
		bool unfocus();
		bool is_focus() { return is_focused_; }
		bool is_hover(); // need redesign
	    void draw(Graphics& g, int x, int y, size_t z);

	    short get_line_lengh() { return line_lengh_; }

		//D'tors
		~ListItem();

};