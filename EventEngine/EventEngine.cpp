#include "EventEngine.h"
#include <vector>
#include <algorithm>
using namespace std;

EventEngine::EventEngine(DWORD input, DWORD output)
	: _console(GetStdHandle(input)), _graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void EventEngine::run(Control &c)
{
	for (bool redraw = true;;)
	{
		if (redraw)
		{
			_graphics.clearScreen();
			_graphics.setCursorVisibility(false);
			for (size_t z = 0; z < 5; ++z)
			{
				c.draw(_graphics, 0, 0, z);
			}	
			redraw = false;
		}

		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		switch (record.EventType)
		{
			case KEY_EVENT:
			{
				auto f = Control::get_focus();
				if (f != nullptr && record.Event.KeyEvent.bKeyDown)
				{
					auto code = record.Event.KeyEvent.wVirtualKeyCode;
					auto chr = record.Event.KeyEvent.uChar.AsciiChar;
					if (code == VK_TAB)
						moveFocus(c, f);
					else
						redraw = f->KeyDown(code, chr);
				}
				break;
			}
			case MOUSE_EVENT:
			{
				auto button = record.Event.MouseEvent.dwButtonState;
				auto coord = record.Event.MouseEvent.dwMousePosition;
				auto event = record.Event.MouseEvent.dwEventFlags;
				auto x = coord.X - c.get_left();
				auto y = coord.Y - c.get_top();
				if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
				{
					redraw = c.MousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
				} else if(event == MOUSE_MOVED) {
                    redraw = c.MouseHover(x, y, _graphics);
                }
				break;
			}
			default:
				break;
			}
	}
}

EventEngine::~EventEngine()
{
	SetConsoleMode(_console, _consoleMode);
}

void EventEngine::moveFocus(Control &main, Control *focused)
{
	vector<Control*> controls;
	main.get_all_controls(&controls);
	auto it = find(controls.begin(), controls.end(), focused);
	do
		if (++it == controls.end())
			it = controls.begin();
	while (!(*it)->CanGetFocus());
	Control::set_focus(**it);
}