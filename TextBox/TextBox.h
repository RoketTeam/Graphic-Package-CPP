#pragma once

#include <string>
#include <Windows.h>
#include "IControl.h"

using namespace std;

class TextBox : public Control
{
	private:
		int length_;
		Label value_;

	public:

		TextBox(COORD pos, int Length, string name)
			: position(pos), length(Length), value(name) {
		}; // need to be refactor

		string getValue() {
			return value_;
		}

		void setFrame(int Length);
		void addChar(char ch);
		void deleteChar();
		~TextBox() {};


};

