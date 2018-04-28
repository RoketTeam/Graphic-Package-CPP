//
// Created by Shaked Zrihen on 28/04/2018.
//

#include <windows.h>
#include "CheckList.h"


CheckList::CheckList(int numberOfOptions, string *options, short positionX, short positionY):
        _listSize(numberOfOptions),
        _position({positionX, positionY})
{
    _stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(_stdoutHandle, FOREGROUND_GREEN);
    for(short i = 0 ; i < _listSize; ++i){
        _items.push_back(ListItem(_position.X, _position.Y + i, options[i]));
    }
}

void CheckList::Draw() {
    SetConsoleCursorPosition(_stdoutHandle, _position);
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    GetConsoleScreenBufferInfo(_stdoutHandle, &consoleScreenBufferInfo);

    CONSOLE_CURSOR_INFO consoleCursorInfo = { 100, FALSE };
    SetConsoleCursorInfo(_stdoutHandle, &consoleCursorInfo);

    for(short i = 0 ; i < _listSize; ++i){
        _items[i].Draw();
    }
}

bool CheckList::HandleInputRecord(INPUT_RECORD inputRecord) {

    switch (inputRecord.EventType) {
        case KEY_EVENT:
            KeyEventProc(inputRecord.Event.KeyEvent);
            break;
        case MOUSE_EVENT:
            MouseEventProc(inputRecord.Event.MouseEvent);
            break;
    }

}

void CheckList::KeyEventProc(KEY_EVENT_RECORD keyEventRecord) {
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    GetConsoleScreenBufferInfo(_stdoutHandle, &consoleScreenBufferInfo);
    // if key pressed
    if (keyEventRecord.bKeyDown) {
        ListItem* currentItem = nullptr;
        int index = -1;
        for(int i=0 ; i<_listSize ; ++i) {
            if (_items[i].IsFocus()){
                currentItem = &_items[i];
                index = i;
            }
        }
        if(!currentItem){
            index = -1;
        }

        //Down key pressed
        if(keyEventRecord.wVirtualKeyCode == 40) {
            if(currentItem)
                currentItem->Unfocus();
            if(index == _listSize - 1) {
                _items[0].Focus();
            }
            else {
                _items[index+1].Focus();
            }
            return;

        }

        //Space key pressed
        if (keyEventRecord.wVirtualKeyCode == VK_SPACE) {
            _items[index].Click();
            return;
        }

        //Up key pressed
        if (keyEventRecord.wVirtualKeyCode == VK_UP) {
            if(currentItem)
                currentItem->Unfocus();

            if(index == 0 || index == -1) {
                _items[_listSize - 1].Focus();
            }
            else {
                _items[index - 1].Focus();
            }
            return;

        }
    }
}


CheckList::~CheckList() {}