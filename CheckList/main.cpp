#include "CheckList.h"


int main (int argc, char *argv[]) {

    string test[] = { "Ligal Levy", "Chen Keselman", "Avraham Lachmi", "Shaked Zrihen" };
    CheckList list(4, test, 4, 4);
    list.Draw();
    HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
    while (1) {
        INPUT_RECORD inputRecord;
        DWORD count;
        ReadConsoleInput(in, &inputRecord, 1, &count);
        list.HandleInputRecord(inputRecord);
    }
}
