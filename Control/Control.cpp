#include "Control.h"
#include "../IBorder/NoneBorder.h"


using namespace std;

Control::Control()
{
    left_ = 0;
    top_ = 0;
    border_ = new NoneBorder();
}



Control::Control(int left, int top, IBorder* border):
        left_(left), top_(top), border_(border){}




Control::~Control() {}
