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


TextBox::TextBox() :
        Control(), length_(10), value_("")
{
    is_focus_ = false;
    height_ = 3;
};

TextBox::TextBox(short left, short top, int length) :
        Control(), length_(length), value_("")
{
    if (length < 0) {
        length_ = 0;
    }
    set_left(left);
    set_top(top);
    is_focus_ = false;
};


TextBox::TextBox(short left, short top, int length, string value) :
        Control(), length_(length), value_(value)
{
    if (length < 0 || length < value.length()) {
        length_ = value.length();
    }

    set_left(left);
    set_top(top);
    highlight_index_ = value.length();
    is_focus_ = false;
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
    if (length < 0 || length < value_.get_text().length()) {
        length_ = value_.get_text().length();
    }
    else length_ = length;
}

void TextBox::set_highlight(int index) {
    Graphics _graphics(STD_OUTPUT_HANDLE);
    if (index >= value_.get_text().length()) {
        index = value_.get_text().length();
    }
    if (index <= 0) {
        index = 0;
    }
    highlight_index_ = index;
}

void TextBox::add_char(int x, char ch) {
    if (length_ > value_.get_text().length()) {
        value_.set_text(value_.get_text().insert(highlight_index_, 1, ch));
        set_highlight(highlight_index_ + 1);
    }
}

void TextBox::delete_char() {
    if (value_.get_text().length() > 0) {
        value_.set_text(value_.get_text().erase(highlight_index_, 1));
        set_highlight(highlight_index_ - 1);
    }
}

void TextBox::delete_all_text() {
    value_.set_text("");
    set_highlight(0);
}

void TextBox::draw(Graphics& g, int x, int y, size_t z = 0) {
    if (!z)
    {
        left_ = x;
        top_ = y;
        Color background = g.getBackground();
        Color foreground = g.getForeground();
        if (background_ != Color::Transparent)
            g.setBackground(background_);
        if (foreground_ != Color::Transparent)
            g.setForeground(foreground_);
        border_->drawBorder(x, y, length_ + 1, g);
        value_.draw(g, x, y, 0);

        g.moveTo(left_ + highlight_index_ + 1, top_ + 1);
        g.setCursorVisibility(is_focus_);
    }
}



void TextBox::KeyDown(int keyCode, char character) {
    if ((keyCode >= 0x30 && keyCode <= 0x39) || (keyCode >= 0x41 && keyCode <= 0x5A)) {
        add_char(0, character);
    }
    else if (keyCode == VK_BACK) {
        delete_char();
    }
    else if (keyCode == VK_DELETE) {
        delete_all_text();
    }
    else if (keyCode == VK_LEFT || keyCode == VK_NUMPAD4) {
        if (highlight_index_ > 0) {
            set_highlight(highlight_index_ - 1);
        }
    }
    else if (keyCode == VK_RIGHT || keyCode == VK_NUMPAD6) {
        if (this->highlight_index_ <= (value_.get_text().length() - 1)) {
            set_highlight(highlight_index_ + 1);
        }
    }
}

void TextBox::MousePressed(int x, int y, bool isLeft) {
    x--;
    y--;
    if (isLeft) {
        set_highlight(x);
    }
    set_focus(*this);
};


bool TextBox::MouseHover(int x, int y, Graphics &g) {
    return value_.MouseHover(x, y, g);
}
