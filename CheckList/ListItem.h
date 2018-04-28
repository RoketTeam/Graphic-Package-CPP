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
        HANDLE _stdoutHandle;
        COORD _position;
        string _descriptionLabel;
        short _lineLengh;
        bool _isChecked;
        bool _isFocusd;

        // Methods
        void markAsChoose();
        void markAsUnchoose();
        bool setColor(DWORD color);



public:
        // C'tors
        ListItem(short positionX, short positionY, string description);
        // methods
        void draw();
        bool setBackgroundColor(DWORD background);
        bool setTextColor(DWORD textColor);
        void click();
        bool focus();
        bool unfocus();

        //D'tors
        ~ListItem();

};