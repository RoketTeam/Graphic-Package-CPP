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
        _isFocusd = false;

}


void ListItem::Draw() {
    SetConsoleCursorPosition(_stdoutHandle, _position);
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    GetConsoleScreenBufferInfo(_stdoutHandle, &consoleScreenBufferInfo);

    CONSOLE_CURSOR_INFO consoleCursorInfo = { 100, FALSE };
    SetConsoleCursorInfo(_stdoutHandle, &consoleCursorInfo);
    if(_isChecked){
        cout << "[X] " << _descriptionLabel << endl;
    } else {
        cout << "[ ] " << _descriptionLabel << endl;
    }
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
    _isFocusd = true;
    return SetBackgroundColor(BACKGROUND_GREEN);
}

bool ListItem::Unfocus() {
    _isFocusd = false;
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
        if(_isFocusd){
            Focus();
        }
    } else {
        MarkAsChoose();
        if(_isFocusd){
            Focus();
        }
    }
}

ListItem::~ListItem() {}
