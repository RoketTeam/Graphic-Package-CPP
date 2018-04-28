//
// Created by Shaked Zrihen on 28/04/2018.
//

#include "ListItem.h"

ListItem::ListItem(short positionX, short positionY, string description):
        _position({positionX, positionY}),
        _descriptionLabel(description)
{
        _stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        _lineLengh = _descriptionLabel.length() + 6;

}


void ListItem::draw() {

        SetConsoleCursorPosition(_stdoutHandle, _position);
        CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
        GetConsoleScreenBufferInfo(_stdoutHandle, &consoleScreenBufferInfo);

        CONSOLE_CURSOR_INFO consoleCursorInfo = { 100, FALSE };
        SetConsoleCursorInfo(_stdoutHandle, &consoleCursorInfo);
        cout << "[ ] " + _descriptionLabel << endl;
}

bool ListItem::setBackgroundColor(DWORD background) {
    DWORD bg;
    SetConsoleCursorPosition(_stdoutHandle, _position);
    WINBOOL seccessStatus = FillConsoleOutputAttribute(_stdoutHandle, background, _lineLengh, _position, &bg);
    return (bool)seccessStatus;
}

ListItem::~ListItem() {}
