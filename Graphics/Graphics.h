#pragma once

#include <string>
#include <windows.h>

using namespace std;

enum class Color { Black, Blue, Green, Red, Cyan, Purple, Orange, White };

class Graphics
{
    public:
        Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
        void clearScreen();
        void moveTo(int x, int y);
        void setBackground(Color color);
        void setBackground(Color color, short lineLength, short x, short y);
        void setForeground(Color color);
        void write(string s);
        void write(int x, int y, string s);
        void write(wstring s);
        void write(int x, int y, wstring s);
        void setCursorVisibility(bool isVisible);
    private:
        HANDLE _console;
        DWORD getBackgroundColor(Color color);
        DWORD getForegroundColor(Color color);
        Color _background, _foreground;
        void updateConsoleAttributes();
};

bool isInside(int x, int y, int left, int top, int width, int height);