//
// Created by Shaked Zrihen on 28/04/2018.
//

#include "ListItem.h"

ListItem::ListItem(short position_x, short position_y, string description):
        position_({position_x, position_y}),
        description_label_(description)
{
        stdout_handle_ = GetStdHandle(STD_OUTPUT_HANDLE);
        line_lengh_ = (short)(description_label_.length() + 6);
        is_checked_ = false;
        is_focused_ = false;

}


void ListItem::Draw() {
    SetConsoleCursorPosition(stdout_handle_, position_);
    CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
    GetConsoleScreenBufferInfo(stdout_handle_, &console_screen_buffer_info);

    CONSOLE_CURSOR_INFO console_cursor_info = { 100, FALSE };
    SetConsoleCursorInfo(stdout_handle_, &console_cursor_info);

    if(is_checked_) {
        cout << "[X] ";
    }
    else{
        SetConsoleTextAttribute(stdout_handle_, BACKGROUND_GREEN);
        cout << "[ ] " << description_label_;
    }
    if(is_focused_)
        Focus();
    else
        Unfocus();

}

bool ListItem::SetColor(DWORD color) {
    DWORD bg;
    SetConsoleCursorPosition(stdout_handle_, position_);
    bool seccessStatus = (bool) FillConsoleOutputAttribute(
            stdout_handle_,
            color,
            line_lengh_,
            position_,
            &bg
    );
    return seccessStatus;
}

bool ListItem::SetBackgroundColor(DWORD background) {
    return SetColor(background);
}

bool ListItem::SetTextColor(DWORD text_color) {
    return SetColor(text_color);
}

bool ListItem::Focus() {
    is_focused_ = true;
    return SetBackgroundColor(BACKGROUND_GREEN);
}

bool ListItem::Unfocus() {
    is_focused_ = false;
    return SetTextColor(FOREGROUND_GREEN);
}

void ListItem::MarkAsUnchoose() {
    is_checked_ = false;
    Draw();
}

void ListItem::MarkAsChoose() {
    is_checked_ = true;
    Draw();
}

void ListItem::Click() {
    if(is_checked_) {
        MarkAsUnchoose();
    } else {
        MarkAsChoose();
    }
}

bool ListItem::IsHover(MOUSE_EVENT_RECORD mouseEventRecord) {
    return mouseEventRecord.dwMousePosition.X > position_.X &&
           mouseEventRecord.dwMousePosition.X < position_.X + line_lengh_ &&
           mouseEventRecord.dwMousePosition.Y == position_.Y;
}

ListItem::~ListItem() {}
