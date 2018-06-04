#pragma once

#include <string>
#include <Windows.h>
#include "IControl.h"

using namespace std;

class TextBox : public IControl
{
	private:
		COORD position;
		int length;
		string value;

	public:

		TextBox(COORD pos, int Length, string name)
			: position(pos), length(Length), value(name) {
		};

		string getValue() {
			return value;
		}

		COORD getPosition() {
			return position;
		}



		void setFrame(int Length);
		void addChar(char ch);
		void deleteChar();
		void deleteAllText();
		void gotoXY(int x, int y);
		void gotoXY(int x, int y, string text);

		void draw();

		~TextBox() {};


};

