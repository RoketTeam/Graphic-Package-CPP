#include "Control.h"



Control::Control()
{
    left_ = 0;
    top_ = 0;
    border_ = NULL;
}

Control::Control(int left, int top, IBorder* border):
        left_(left), top_(top), border_(border){}


Control::~Control() {}
