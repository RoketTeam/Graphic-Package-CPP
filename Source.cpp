#include <stdio.h>
#include <Windows.h>
#include "TextBox.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);

	TextBox d({ 25,10 }, 20, "Text");
	d.draw();

	int counter = 0;
	while (1) {
		INPUT_RECORD ir;
		DWORD count;
		ReadConsoleInput(in, &ir, 1, &count);
		switch (ir.EventType) {
		case KEY_EVENT:
			if (!counter) {
				if (ir.Event.KeyEvent.uChar.AsciiChar >= 32 && ir.Event.KeyEvent.uChar.AsciiChar <= 127) {
					d.addChar(ir.Event.KeyEvent.uChar.AsciiChar);
				}
				else if (ir.Event.KeyEvent.uChar.AsciiChar == 0 || ir.Event.KeyEvent.uChar.AsciiChar == 128) {
					d.deleteAllText();
				}
				else if (ir.Event.KeyEvent.uChar.AsciiChar == 8) {
					d.deleteChar();
				}
			}
			if (counter == 0) {
				counter++;
			}
			else {
				counter = 0;
			}
		}
	}




}