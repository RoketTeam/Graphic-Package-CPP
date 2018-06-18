#include "../Label/Label.h"
#include "../IBorder/IBorder.h"
#include <iostream>


Label::Label(string text) : Control(), text_(text) {
    width_ = text_.length() + 2;
    height_ = 3;
};


void Label::setLeft(short left) {
    left_ = left;
}

void Label::setTop(short top) {
    top_ = top;
}

void Label::setText(string text) {
    text_ = text;
}

string Label::getText() {
    return text_;
}

void Label::draw(Graphics& g, int x, int y, size_t z) {
    if (z == 0) {
        top_ = y;
        left_ = x;
        width_ = text_.length() + 2;
        border_->drawBorder(left_, top_, width_ - 2, g);
        g.write(left_ + 1, top_ + 1, text_);
    }
}

Label::~Label() {}

