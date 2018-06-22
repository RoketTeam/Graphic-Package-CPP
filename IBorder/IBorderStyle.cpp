#include "../IBorder/IBorderStyle.h"
#include "../Control/Control.h"


IBorderStyle::IBorderStyle(char topCorner,
                           char horizontalLine,
                           char topRightCorner,
                           char verticalLine,
                           char bottomLeftCorner,
                           char bottomRightCorner):
        topCorner(topCorner),
        horizontalLine(horizontalLine),
        topRightCorner(topRightCorner),
        verticalLine(verticalLine),
        bottomLeftCorner(bottomLeftCorner),
        bottomRightCorner(bottomRightCorner){}

void IBorderStyle::drawBorder(int top, int left, int length, Graphics& g, int amount){
    string Line(length, horizontalLine);
    string Fill(length , ' ');
    int col = top;
    int row = left;
    g.moveTo(col, row);
    cout << topCorner << Line << topRightCorner;
    int a;
    for (a = 1; a <amount - 1;a++)
    {
        g.moveTo(col, row + a);
        cout << verticalLine;
        cout << Fill;
        cout << verticalLine;
    }

    g.moveTo(col, (amount + row) - 1);
    cout << bottomLeftCorner << Line << bottomRightCorner;
}


