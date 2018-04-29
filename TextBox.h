#pragma once

#include <string>
#include <Windows.h>

using namespace std;

class TextBox
{
    private:
        COORD position;
        int length;
        string value;

    public:

        TextBox(COORD pos, int Length, string name)
                : position(pos), length(Length), value(name) {
        };

        string GetValue() {
            return value;
        }

        COORD GetPosition() {
            return position;
        }



        void GetFrame(int Length);
        void AddChar(char ch);
        void DeleteChar();
        void GoToXY(int x, int y);
        void GoToXY(int x, int y, string text);
        void SetFrame(int length);
        void Draw();

        ~TextBox() {};


};