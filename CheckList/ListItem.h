//
// Created by Shaked Zrihen on 28/04/2018.
//

# pragma once

#include <windows.h>
#include <iostream>
#include <string>

using namespace std;


class ListItem {

    private:
        // Atrributes
        HANDLE stdout_handle_;
        COORD position_;
        string description_label_;
        short line_lengh_;
        bool is_checked_;
        bool is_focused_;

        // Methods
        void MarkAsChoose();
        void MarkAsUnchoose();
        bool SetColor(DWORD color);



public:
        // C'tors
        ListItem(short position_x, short position_y, string description);

        // methods
        void Draw();
        bool SetBackgroundColor(DWORD background);
        bool SetTextColor(DWORD textColor);
        void Click();
        bool Focus();
        bool Unfocus();
        bool IsFocus(){return is_focused_;}
        bool IsHover(MOUSE_EVENT_RECORD mouseEventRecord);
        short GetLineLengh(){return line_lengh_;}

        //D'tors
        ~ListItem();

};