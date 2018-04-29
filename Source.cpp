#include <stdio.h>
#include <Windows.h>
#include "TextBox.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    HANDLE in = GetStdHandle(STD_INPUT_HANDLE);

    TextBox d({ 25,10 }, 20, "Text");
    d.Draw();

    int counter = 0;
    while (1) {
        INPUT_RECORD ir;
        DWORD count;
        ReadConsoleInput(in, &ir, 1, &count);
        d.HandleEvent(ir, &counter);
    }
}