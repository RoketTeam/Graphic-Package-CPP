#pragma once

#include <string>
#include <Windows.h>
#include "IControl.h"

using namespace std;

class Label : public IControl
{
	private:
		COORD _position;
		string _value;
		DWORD _bg;
		DWORD _fg;

	public:
	
		Label(COORD pos, string name) 
			: _position(pos), _value(name) {
			this->_bg = 0;
			this->_fg = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		};

		string getValue() {
			return _value;
		}

		COORD getPosition() {
			return _position;
		}

		void setBackground(DWORD bg);
		void setForeground(DWORD fg);

		void draw();

		~Label() {};


};

