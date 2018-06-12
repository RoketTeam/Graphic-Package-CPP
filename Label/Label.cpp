#include "../Label/Label.h"
#include "../IBorder/IBorder.h"
#include <iostream>


Label::Label(string text) : Control(), text_(text) {
    width_ = text_.length();
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
        border_->drawBorder(top_, left_, this->getText().length(), g);
        g.write(top_ + 1, left_ + 1, text_);
    }
}

Label::~Label() {}

