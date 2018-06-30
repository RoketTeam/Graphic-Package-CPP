
#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include "../Label/Label.h"

using namespace std;


class ListItem : public Control {


	public:
		// C'tors & D'tors
		ListItem(string description);
        ~ListItem(){};

        // Setters & Getters
        short get_line_length() { return line_length_; }

		// Methods
		void focus();
		void unfocus();
		bool is_focus() { return is_focused_; }
	    void draw(Graphics& g, int x, int y, size_t z);

        // Event handlers
        void MousePressed(int x, int y, bool isLeft);
        bool MouseHover(int x, int y, Graphics &g);
        void KeyDown(int keyCode, char character){};


    private:
        // Atrributes
        Label description_label_;
        short line_lengh_;
        bool is_checked_;
        bool is_focused_;


        // Methods
        void MarkAsChoose();
        void MarkAsUnchoose();
};