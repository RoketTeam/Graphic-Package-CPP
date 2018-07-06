
#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include "../Label/Label.h"
#include "../IBorder/IBorderStyle.h"
#include "../IBorder/NoneBorder.h"

using namespace std;


class ListItem : public Control {


	public:
		// C'tors & D'tors
		ListItem(string description);
        ~ListItem(){};

        // Setters & Getters
		string get_text(){return description_label_.get_text();}
        short get_line_length() { return line_length_; }

		// Methods
		void focus();
		void unfocus();
		bool is_focus() { return is_focused_; }
		bool is_checked() { return is_checked_; }
	    void draw(Graphics& g, int x, int y, size_t z);
        void MarkAsUnchecked(){is_checked_ = false;};
        void MarkAsChecked(){is_checked_ = true;}

        // Event handlers
        void MousePressed(int x, int y, bool isLeft);
        bool MouseHover(int x, int y, Graphics &g);
        void KeyDown(int keyCode, char character){}



    private:
        // Atrributes
        Label description_label_;
        short line_length_;
        bool is_checked_;
        bool is_focused_;



};