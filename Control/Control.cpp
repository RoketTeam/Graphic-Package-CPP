#include "Control.h"
#include "../IBorder/NoneBorder.h"


using namespace std;

Control* Control::focused_control = nullptr;

Control::Control()
{
    left_ = 0;
    top_ = 0;
    border_ = new NoneBorder();
    background_ = Color::Transparent;
    foreground_ = Color::Transparent;
}


Control::Control(int left, int top, IBorder* border):
        left_(left), top_(top),
        border_(border){}


Control::~Control() {}

void Control::FillBackground(short x, short y, int height, Graphics & g) {
    string Line(height,  ' ');
    string Fill(height , ' ');
    int col = x;
    int row = y;
    g.moveTo(col, row);
    cout << ' ' << Line << ' ';
    int a, amount = 3;
    for (a = 1; a <amount;a++)
    {
        g.moveTo(col, row + a);
        cout << ' ';
        cout << Fill;
        cout << ' ';
    }
}