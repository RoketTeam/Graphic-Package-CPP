#pragma once

#include <string>
#include <Windows.h>
#include "../Control/Control.h"

using namespace std;

class Label : public Control
{
	public:

		//  C'tors & D'tors
        Label(string text);
        ~Label();

        // Setters & Getters
        void set_text(string text);
        void set_left(short left);
        void set_top(short top);
        string get_value(){ return get_text();}
		string get_text();

		// Methods
		void draw(Graphics& g, int x, int y, size_t z);
		bool MouseHover(int x, int y, Graphics &g){ return false;}

    private:
        string text_;

};

