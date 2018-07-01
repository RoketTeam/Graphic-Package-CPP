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


TextBox::TextBox() : Control(), IListener(),
length_(10),
value_("") {};

TextBox::TextBox(short left, short top, int length) : Control(), //IListener(),
length_(length),
value_("")
{
	setLeft(left);
	setTop(top);
};


TextBox::TextBox(short left, short top, int length, string value) : Control(), // IListener(), 
length_(length), value_(value)
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

void TextBox::addChar(int x, Graphics &g, char ch) {
	if (length_ > value_.getText().length()) {
		value_.setText(value_.getText() += ch);
		g.write(this->left_ + 1, this->top_ + 1, value_.getText());
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

void TextBox::draw(Graphics& g) {
	value_.setBorder(this->border_);
	value_.draw(g, this->left_, this->top_, length_, 0);
}

void TextBox::action(IObservable * iObservable)
{
}

void TextBox::keyPressed(CHAR AsciiChar, Graphics& g)
{
	if (AsciiChar >= 32 && AsciiChar <= 127) {
		addChar(0, g, AsciiChar);
	}
	else if (AsciiChar == 128) { //ir.Event.KeyEvent.uChar.AsciiChar == 0 
		deleteAllText();
	}
	else if (AsciiChar == 8) {
		deleteChar();
	}
}


