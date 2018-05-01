#include "CheckList.h"


int main (int argc, char *argv[]) {

    string test[] = { "Ligal Levy", "Chen Keselman", "Avraham Lachmi", "Shaked Zrihen" };
    CheckList list(4, test, 4, 4);
    list.Draw();
    HANDLE std_input_handle = GetStdHandle(STD_INPUT_HANDLE);
    while (1) {
        INPUT_RECORD input_record;
        DWORD count;
        ReadConsoleInput(std_input_handle, &input_record, 1, &count);
        list.HandleInputRecord(input_record);
    }
}
