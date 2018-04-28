
#pragma once

#include <vector>
#include "ListItem.h"

class CheckList {
    private:
        COORD _position;
        vector<ListItem> _items;
        int _listSize;
        HANDLE _stdoutHandle;

        //Methods:
        bool CheckMousePosition(COORD mousePosition);

    public:
        CheckList(int numberOfOptions, string options[], short positionX, short positionY);
        bool HandleInputRecord(INPUT_RECORD inputRecord);
        void Draw();
        void KeyEventProc(KEY_EVENT_RECORD keyEventRecord);
        void MouseEventProc(MOUSE_EVENT_RECORD mouseEventRecord);

    ~CheckList();

};