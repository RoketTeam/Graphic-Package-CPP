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


TextBox::TextBox(Graphics &g) : Control(), IListener(),
length_(10),
graphic_(&g),
value_("") {};

TextBox::TextBox(short left, short top, int length, Graphics &g) : Control(), //IListener(),
length_(length),
graphic_(&g),
value_("")
{
	setLeft(left);
	setTop(top);
};


TextBox::TextBox(short left, short top, int length, string value, Graphics &g) : Control(), // IListener(), 
length_(length),
graphic_(&g),
value_(value)
{
	setLeft(left);
	setTop(top);
};


void TextBox::setLeft(short left) {
	if (left < 0) { left = 0; }
	left_ = left;
}

void TextBox::setTop(short top) {
	if (top < 0) { top = 0; }
	top_ = top;
}

void TextBox::setFrameSize(int length) {
	this->length_ = length;
}

void TextBox::addChar(int x, char ch) {
	if (length_ > value_.getText().length()) {
		value_.setText(value_.getText() += ch);
		graphic_->write(this->left_ + 1, this->top_ + 1, value_.getText());
	}
}

void TextBox::deleteChar() {
	if (value_.getText().length() > 0) {
		value_ = value_.getText().substr(0, value_.getText().size() - 1);
		cout << '\b' << " " << '\b';
	}
}

void TextBox::deleteAllText() {
	if (value_.getText().length() > 0) {
		for (int i = 0; i < value_.getText().length(); i++)
		{
			cout << '\b' << " " << '\b';
		}
		value_.setText("");
	}
}

//
//void notify();
//void add(IListener* listener);

void TextBox::draw(Graphics& g, int x = -1, int y = -1, size_t z = 0) {
	if (!z)
	{
		if (graphic_ != &g) {
			delete(graphic_);
			graphic_ = &g;
		}
		if (x != -1) {
			this->left_ = x;
		}
		if (y != -1) {
			this->top_ = y;
		}

		value_.setBorder(this->border_);
		value_.draw(g, this->left_, this->top_, length_, 0);
	}
}

void TextBox::action(IObservable * iObservable)
{
	//need to complete
}

void TextBox::keyDown(int keyCode, char character)
{
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


