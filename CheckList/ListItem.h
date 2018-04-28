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
        void MarkAsChoose();
        void MarkAsUnchoose();
        bool SetColor(DWORD color);



public:
        // C'tors
        ListItem(short positionX, short positionY, string description);
        // methods
        void Draw();
        bool SetBackgroundColor(DWORD background);
        bool SetTextColor(DWORD textColor);
        void Click();
        bool Focus();
        bool Unfocus();

        //D'tors
        ~ListItem();

};