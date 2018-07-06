#include "../Label/Label.h"
#include "../IBorder/IBorder.h"
#include <iostream>


Label::Label(string text) :
        Control(), text_(text)
{
    width_ = text_.length() + 2;
    height_ = 3;
};


void Label::set_left(short left) {
    left_ = left;
}

void Label::set_top(short top) {
    top_ = top;
}

void Label::set_text(string text) {
    text_ = text;
}

string Label::get_text() {
    return text_;
}

void Label::draw(Graphics& g, int x, int y, size_t z) {
    if (z == 0) {
        top_ = y;
        left_ = x;
        width_ = text_.length() + 2;
        Color background = g.getBackground();
        Color foreground = g.getForeground();
        if(background_ != Color::Transparent)
            g.setBackground(background_);
        if(foreground_ != Color::Transparent)
            g.setForeground(foreground_);
        border_->drawBorder(x, y, width_ - 2, g);
        g.write(x+ 1, y + 1, text_);
        g.setBackground(background);
        g.setForeground(foreground);
    }
}

Label::~Label() {}

