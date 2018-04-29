#include "TextBox.h"
#include <iostream>

void TextBox::SetFrame(int length) {
    this->length = length;
}

void TextBox::AddChar(char ch) {
    if (length > value.length()) {
        value += ch;
        GoToXY(position.X, position.Y, value);
    }
}
void TextBox::DeleteChar() {
    if (value.length() > 0) {
        value = value.substr(0, value.size() - 1);
        cout << '\b' << " " << '\b';
    }
}

void TextBox::GoToXY(int x, int y) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(out, position);
}

void TextBox::GoToXY(int x, int y, string text) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(out, position);
    cout << text;
}

void TextBox::Draw() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;

    char tl, tr, bl, br, side, edge;
    char box[6];
    int col, row;

    col = position.X;
    row = position.Y;

    box[0] = '\xDA';//  ┌
    box[1] = '\xBF';//  ┐
    box[2] = '\xC0';//  └
    box[3] = '\xD9';//  ┘
    box[4] = '\xB3';//  │
    box[5] = '\xC4';//  ─

    tl = box[0];
    tr = box[1];
    bl = box[2];
    br = box[3];
    side = box[4];
    edge = box[5];

    string Line(length, edge);
    string Fill(length, ' ');
    GoToXY(col, row);
    cout << tl << Line << tr;
    int a, amount = 3;
    for (a = 1; a <amount - 1;a++)
    {
        GoToXY(col, row + a);
        cout << side;
        cout << Fill;
        cout << side;
    }

    GoToXY(col, (amount + row) - 1);
    cout << bl << Line << br;
    GoToXY(col + 1, row + 1, value);
}

void TextBox::HandleEvent(INPUT_RECORD inputRecord, int* counter) {
    switch (inputRecord.EventType) {
        case KEY_EVENT:
            if (!(*counter)) {
                if (inputRecord.Event.KeyEvent.uChar.AsciiChar >= 32 && inputRecord.Event.KeyEvent.uChar.AsciiChar <= 127) {
                    AddChar(inputRecord.Event.KeyEvent.uChar.AsciiChar);
                }
                else if (inputRecord.Event.KeyEvent.uChar.AsciiChar == 8) {
                    DeleteChar();
                }
            }
            if ((*counter) == 0) {
                (*counter)++;
            }
            else {
                (*counter) = 0;
            }
    }
}