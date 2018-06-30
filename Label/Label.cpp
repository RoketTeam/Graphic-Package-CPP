#include "../Label/Label.h"
#include "../IBorder/IBorder.h"
#include <iostream>


Label::Label(string text) : Control(), text_(text) {
    width_ = text_.length() + 2;
    height_ = 3;
    background_ = Color ::Transparent;
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
	Label::draw(g, x, y, text_.length(), z);
}

void Label::draw(Graphics& g, int x, int y, int length, size_t z) {
	if (z == 0) {
		top_ = y;
		left_ = x;
		width_ = length + 2;
		Color background = g.getBackground();
		Color foreground = g.getForeground();
		if (background_ != Color::Transparent)
			g.setBackground(background_);
		if (foreground_ != Color::Transparent)
			g.setForeground(foreground_);
		border_->drawBorder(left_, top_, width_ - 2, g, 3);
		g.write(left_ + 1, top_ + 1, text_);
		g.setBackground(background);
		g.setForeground(foreground);
	}
}

Label::~Label() {}

