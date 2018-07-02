#include "TextBox.h"
#include "../IBorder/OneLine.h"
#include "../Label/Label.h"
#include "../IObserver/IObservable.h"
#include "../IListener/IListener.h"
#include "../Button/Button.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>


using namespace std;


TextBox::TextBox(Graphics &g) : 
	Control(), length_(10), graphic_(&g), value_("")
{};

TextBox::TextBox(short left, short top, int length, Graphics &g) : 
	Control(), length_(length), graphic_(&g), value_("")
{
	set_left(left);
	set_top(top);
};


TextBox::TextBox(short left, short top, int length, string value, Graphics &g) : 
	Control(), length_(length), graphic_(&g), value_(value)
{
	set_left(left);
	set_top(top);
};


void TextBox::set_left(short left) {
	if (left < 0) { left = 0; }
	left_ = left;
}

void TextBox::set_top(short top) {
	if (top < 0) { top = 0; }
	top_ = top;
}

void TextBox::set_frame_size(int length) {
	if (length < 0) { length = 0; }
	length_ = length;
}

void TextBox::addChar(int x, char ch) {
	if (length_ > value_.get_text().length()) {
		value_.set_text(value_.get_text() += ch);
		graphic_->write(this->left_ + 1, this->top_ + 1, value_.get_text());
	}
}

void TextBox::deleteChar() {
	if (value_.get_text().length() > 0) {
		value_ = value_.get_text().substr(0, value_.get_text().size() - 1);
		cout << '\b' << " " << '\b';
	}
}

void TextBox::deleteAllText() {
	if (value_.get_text().length() > 0) {
		for (int i = 0; i < value_.get_text().length(); i++)
		{
			cout << '\b' << " " << '\b';
		}
		value_.set_text("");
	}
}

void TextBox::draw(Graphics& g, int x, int y , size_t z = 0) {
	if (!z)
	{
		if (graphic_ != &g) {
			delete(graphic_);
			graphic_ = &g;
		}
		if (x > 0) {
			this->left_ = x;
		}
		if (y > 0) {
			this->top_ = y;
		}

		value_.set_border(this->border_);
		value_.draw(g, this->left_, this->top_, length_, 0);
	}
}

void TextBox::KeyDown(int keyCode, char character) {
	if (keyCode >= 32 && keyCode <= 127) {
		addChar(0, character);
	}
	else if (keyCode == 8) {
		deleteChar();
	}
	else if (keyCode == 128 || keyCode == 0) {
		deleteAllText();
	}
}

void TextBox::MousePressed(int x, int y, bool isLeft) {
	if (isInside(x, y, value_.get_left(), value_.get_top(), value_.get_width(), value_.get_height()))
		value_.MousePressed(x, y, isLeft);
};


bool TextBox::MouseHover(int x, int y, Graphics &g) {
	return value_.MouseHover(x, y, g);
}


