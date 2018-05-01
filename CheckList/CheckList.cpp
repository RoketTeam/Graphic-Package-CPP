//
// Created by Shaked Zrihen on 28/04/2018.
//

#include <windows.h>
#include "CheckList.h"


CheckList::CheckList(int number_of_options, string *options, short position_x, short position_y):
        list_size_(number_of_options),
        position_({position_x, position_y})
{
    stdout_handle_ = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(stdout_handle_, FOREGROUND_GREEN);
    for(short i = 0 ; i < list_size_; ++i){
        items_.push_back(ListItem(position_.X, position_.Y + i, options[i]));
    }
}

void CheckList::Draw() {
    SetConsoleCursorPosition(stdout_handle_, position_);
    CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
    GetConsoleScreenBufferInfo(stdout_handle_, &console_screen_buffer_info);

    CONSOLE_CURSOR_INFO console_cursor_info = { 100, FALSE };
    SetConsoleCursorInfo(stdout_handle_, &console_cursor_info);

    for(short i = 0 ; i < list_size_; ++i){
        items_[i].Draw();
    }
}

void CheckList::HandleInputRecord(INPUT_RECORD input_record) {
    switch (input_record.EventType) {
        case KEY_EVENT:
            KeyEventProc(input_record.Event.KeyEvent);
            break;
        case MOUSE_EVENT:
            MouseEventProc(input_record.Event.MouseEvent);
            break;
    }
}

bool CheckList::CheckMousePosition(COORD mouse_position) {
    return mouse_position.X >= position_.X &&
            mouse_position.X <= items_[list_size_ - 1].GetLineLengh() &&
            mouse_position.Y >= position_.Y &&
            mouse_position.Y <= position_.Y + list_size_;
}

void CheckList::MouseEventProc(MOUSE_EVENT_RECORD mouse_event_record) {

    switch (mouse_event_record.dwEventFlags){
        case MOUSE_MOVED:
            if (CheckMousePosition(mouse_event_record.dwMousePosition)){
                for(int i = 0; i < list_size_ ; ++i){
                    if(items_[i].IsHover(mouse_event_record)){
                        items_[i].Focus();
                    }
                    else {
                        items_[i].Unfocus();
                    }
                }
            }
            return;
        case 0:
            if (mouse_event_record.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                if (CheckMousePosition(mouse_event_record.dwMousePosition)){
                    for(int i = 0; i < list_size_ ; ++i){
                        if(items_[i].IsHover(mouse_event_record)){
                            items_[i].Click();
                        }
                    }
                }
            }
            return;
    }

}

void CheckList::KeyEventProc(KEY_EVENT_RECORD key_event_record) {

    CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
    GetConsoleScreenBufferInfo(stdout_handle_, &console_screen_buffer_info);

    // if key pressed
    if (key_event_record.bKeyDown) {
        ListItem* current_item = nullptr;
        int index = -1;
        for(int i=0 ; i<list_size_ ; ++i) {
            if (items_[i].IsFocus()){
                current_item = &items_[i];
                index = i;
            }
        }
        if(!current_item){
            index = -1;
        }

        //Down key pressed
        if(key_event_record.wVirtualKeyCode == 40) {
            if(current_item)
                current_item->Unfocus();
            if(index == list_size_ - 1) {
                items_[0].Focus();
            }
            else {
                items_[index+1].Focus();
            }
            return;

        }

        //Space key pressed
        if (key_event_record.wVirtualKeyCode == VK_SPACE) {
            items_[index].Click();
            return;
        }

        //Up key pressed
        if (key_event_record.wVirtualKeyCode == VK_UP) {
            if(current_item)
                current_item->Unfocus();

            if(index == 0 || index == -1) {
                items_[list_size_ - 1].Focus();
            }
            else {
                items_[index - 1].Focus();
            }
            return;

        }
    }
}


CheckList::~CheckList() {}