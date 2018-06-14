#include "Graphics.h"

Graphics::Graphics(DWORD stdHandle)
	: _console(GetStdHandle(stdHandle)), _background(Color::Black), _foreground(Color::White)
{
	updateConsoleAttributes();
}

void Graphics::clearScreen()
{
	DWORD d;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(_console, &csbi);
	auto size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputAttribute(_console, csbi.wAttributes, size, { 0, 0 }, &d);
	FillConsoleOutputCharacter(_console, L' ', size, { 0, 0 }, &d);
}

void Graphics::moveTo(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(_console, c);
}

void Graphics::setBackground(Color color)
{
	_background = color;
	updateConsoleAttributes();
}

void Graphics::setBackground(Color color, short lineLength, short x, short y){
	DWORD bg;
	moveTo(x, y);
	DWORD consoleColor = getBackgroundColor(color) | getForegroundColor(Color::White);
	FillConsoleOutputAttribute(_console, consoleColor, lineLength, COORD({x,y}), &bg);
}


void Graphics::setForeground(Color color)
{
	_foreground = color;
	updateConsoleAttributes();
}

void Graphics::write(string s)
{
	WriteConsoleA(_console, s.c_str(), s.size(), nullptr, nullptr);
}

void Graphics::write(wstring s)
{
	WriteConsoleW(_console, s.c_str(), s.size(), nullptr, nullptr);
}

void Graphics::write(int x, int y, string s)
{
	moveTo(x, y);
	write(s);
}

void Graphics::write(int x, int y, wstring s)
{
	moveTo(x, y);
	write(s);
}

void Graphics::setCursorVisibility(bool isVisible)
{
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(_console, &cci);
	cci.bVisible = isVisible;
	SetConsoleCursorInfo(_console, &cci);
}

DWORD Graphics::getBackgroundColor(Color color) {
	DWORD background = 0;

	switch (color)
	{
		case Color::Black:	break;
		case Color::Blue:	background |= BACKGROUND_BLUE; break;
		case Color::Green:	background |= BACKGROUND_GREEN; break;
		case Color::Red:	background |= BACKGROUND_RED; break;
		case Color::Cyan:	background |= BACKGROUND_BLUE | BACKGROUND_GREEN; break;
		case Color::Purple:	background |= BACKGROUND_BLUE | BACKGROUND_RED; break;
		case Color::Orange: background |= BACKGROUND_GREEN | BACKGROUND_RED; break;
		case Color::White:	background |= BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED; break;
	}

	return background;
}

DWORD Graphics::getForegroundColor(Color color) {
	DWORD foreground = 0;

	switch (color)
	{
		case Color::Black:	break;
		case Color::Blue:	foreground |= FOREGROUND_BLUE; break;
		case Color::Green:	foreground |= FOREGROUND_GREEN; break;
		case Color::Red:	foreground |= FOREGROUND_RED; break;
		case Color::Cyan:	foreground |= FOREGROUND_BLUE | FOREGROUND_GREEN; break;
		case Color::Purple:	foreground |= FOREGROUND_BLUE | FOREGROUND_RED; break;
		case Color::Orange: foreground |= FOREGROUND_GREEN | FOREGROUND_RED; break;
		case Color::White:	foreground |= FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED; break;
	}

	return foreground;
}



void Graphics::updateConsoleAttributes()
{
	DWORD attributes = getBackgroundColor(_background) | getForegroundColor(_foreground);
	SetConsoleTextAttribute(_console, attributes);
}

bool isInside(int x, int y, int left, int top, int width, int height)
{
	x -= left;
	y -= top;
	return x >= 0 && y >= 0 && x < width && y < height;
}