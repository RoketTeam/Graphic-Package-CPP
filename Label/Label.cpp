#include "Label.h"
#include <iostream>


Label::Label(string text) : Control(), text_(text) {
    right_  = left_ + 5;
    bottom_ = top_ + text_.length() + 1;
};

void Label::setText(string text) {
    text_ = text;
}

string Label::getText() {
    return text_;
}

void Label::draw(Graphics& g, int x, int y, size_t z) {
    if (z == 0) {
        top_ = x;
        left_ = y;
        g.write(top_, left_, text_);
    }
}

Label::~Label() {}

