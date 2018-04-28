//
// Created by Shaked Zrihen on 28/04/2018.
//

#include "ListItem.h"

ListItem::ListItem(short positionX, short positionY, string description):
        _position({positionX, positionY}),
        _descriptionLabel(description)
{
        _stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        _lineLengh = (short)(_descriptionLabel.length() + 6);
        _isChecked = false;
        _isFocused = false;

}


void ListItem::Draw() {
    SetConsoleCursorPosition(_stdoutHandle, _position);
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    GetConsoleScreenBufferInfo(_stdoutHandle, &consoleScreenBufferInfo);

    CONSOLE_CURSOR_INFO consoleCursorInfo = { 100, FALSE };
    SetConsoleCursorInfo(_stdoutHandle, &consoleCursorInfo);

    if(_isChecked) {
        cout << "[X] ";
    }
    else{
        cout << "[ ] " << _descriptionLabel;
    }
    if(_isFocused)
        Focus();
    else
        Unfocus();

}

bool ListItem::SetColor(DWORD color) {
    DWORD bg;
    SetConsoleCursorPosition(_stdoutHandle, _position);
    WINBOOL seccessStatus = FillConsoleOutputAttribute(_stdoutHandle, color, _lineLengh, _position, &bg);
    return (bool)seccessStatus;
}

bool ListItem::SetBackgroundColor(DWORD background) {
    return SetColor(background);
}

bool ListItem::SetTextColor(DWORD textColor) {
    return SetColor(textColor);
}

bool ListItem::Focus() {
    _isFocused = true;
    return SetBackgroundColor(BACKGROUND_GREEN);
}

bool ListItem::Unfocus() {
    _isFocused = false;
    return SetTextColor(FOREGROUND_GREEN);
}

void ListItem::MarkAsUnchoose() {
    _isChecked = false;
    Draw();
}

void ListItem::MarkAsChoose() {
    _isChecked = true;
    Draw();
}

void ListItem::Click() {
    if(_isChecked) {
        MarkAsUnchoose();
    } else {
        MarkAsChoose();
    }
}

bool ListItem::IsHover(MOUSE_EVENT_RECORD mouseEventRecord) {
    return mouseEventRecord.dwMousePosition.X > _position.X &&
           mouseEventRecord.dwMousePosition.X < _position.X + _lineLengh &&
           mouseEventRecord.dwMousePosition.Y == _position.Y;
}

ListItem::~ListItem() {}
