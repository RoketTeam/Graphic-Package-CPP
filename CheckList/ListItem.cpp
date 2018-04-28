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


void ListItem::draw() {
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

bool ListItem::setColor(DWORD color) {
    DWORD bg;
    SetConsoleCursorPosition(_stdoutHandle, _position);
    WINBOOL seccessStatus = FillConsoleOutputAttribute(_stdoutHandle, color, _lineLengh, _position, &bg);
    return (bool)seccessStatus;
}

bool ListItem::setBackgroundColor(DWORD background) {
    return setColor(background);
}

bool ListItem::setTextColor(DWORD textColor) {
    return setColor(textColor);
}

bool ListItem::focus() {
    _isFocusd = true;
    return setBackgroundColor(BACKGROUND_GREEN);
}

bool ListItem::unfocus() {
    _isFocusd = false;
    return setTextColor(FOREGROUND_GREEN);
}

void ListItem::markAsUnchoose() {
    _isChecked = false;
    draw();
}

void ListItem::markAsChoose() {
    _isChecked = true;
    draw();
}

void ListItem::click() {
    if(_isChecked) {
        markAsUnchoose();
        if(_isFocusd){
            focus();
        }
    } else {
        markAsChoose();
        if(_isFocusd){
            focus();
        }
    }
}

ListItem::~ListItem() {}
