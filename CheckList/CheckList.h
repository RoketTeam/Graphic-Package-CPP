
#pragma once

#include <vector>
#include "ListItem.h"

class CheckList {
    private:
        COORD position_;
        vector<ListItem> items_;
        int list_size_;
        HANDLE stdout_handle_;

        //Methods:
        bool CheckMousePosition(COORD mouse_position);

    public:
        CheckList(int number_of_options, string options[], short position_x, short position_y);
        void HandleInputRecord(INPUT_RECORD input_record);
        void Draw();
        void KeyEventProc(KEY_EVENT_RECORD key_event_record);
        void MouseEventProc(MOUSE_EVENT_RECORD mouse_event_record);

    ~CheckList();

};
