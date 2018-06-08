#include "Label.h"
#include <iostream>


Label::Label(string text) : Control(), text_(text) {};

void Label::setText(string text)
{
    text_ = text;
}


void Label::draw(Graphics& g, int x, int y, size_t z)
{
    if (!z)
        g.write(text_);

}

Label::~Label() {}

