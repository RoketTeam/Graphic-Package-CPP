#include "NumericBox.h"
#include "../IBorder/OneLine.h"
#include <iostream>

using namespace std;


NumericBox::NumericBox(int min_value, int max_value):
        min_value_(min_value),
        max_value_(max_value),
        inc_("+"),
        dec_("-"),
        value_(min_value),
        text_value_(to_string(min_value))
{
    inc_.add(this);
    dec_.add(this);
}

NumericBox::NumericBox():
        min_value_(0),
        max_value_(10),
        inc_("+"),
        dec_("-"),
        value_(0),
        text_value_(to_string(0))
{
    inc_.add(this);
    dec_.add(this);
}


void NumericBox::set_min_value(int value) {
    min_value_ = value;
    if (value_ > min_value_)
        value_ = min_value_;
}


void NumericBox::set_max_value(int value) {
    max_value_ = value;
    if (value_ > max_value_)
        value_ = max_value_;
}

void NumericBox::set_value(int value) {
    if(value <= max_value_ && value >= min_value_)
        value_ = value;
}


int NumericBox::get_value() {
    return value_;
}


void NumericBox::inc() {

    if (max_value_ >= value_+1){
        value_ += 1;
        text_value_.set_text(to_string(value_));
    }
    set_focus(*this);
}

void NumericBox::dec() {
    if (value_ - 1 >= min_value_) {
        value_ -= 1;
        text_value_.set_text(to_string(value_));
    }
    set_focus(*this);
}


void NumericBox::draw(Graphics& g, int x, int y, size_t z){
    if(!z){
        Color background = g.getBackground();
        Color foreground = g.getForeground();
        text_value_.set_left(inc_.get_width());
        dec_.set_left(text_value_.get_left() + text_value_.get_text().length() + 2);
        if(background_ != Color::Transparent)
            g.setBackground(background_);
        if(foreground_ != Color::Transparent)
            g.setForeground(foreground_);
        width_ = dec_.get_left();
        this->FillBackground(x, y, width_, g);
        inc_.draw(g, x, y, 0);
        text_value_.draw(g, text_value_.get_left() + 1, y, 0);
        dec_.draw(g, x + dec_.get_left(), y, 0);
        g.setBackground(background);
        g.setForeground(foreground);
    }
}

void NumericBox::action(IObservable* iObservable) {
    if(!(((Button*)iObservable)->get_text().compare (" - "))){
        inc();
    } else if (!(((Button*)iObservable)->get_text().compare(" + "))) {
        dec();
    }
}

bool NumericBox::MousePressed(int x, int y, bool isLeft) {
    if(!Control::lock_events_){
        if(isInside(x, y, inc_.get_left(), inc_.get_top(), inc_.get_width(), inc_.get_height()))
        {
            inc();
            return true;
        }
        if(isInside(x, y, dec_.get_left(), dec_.get_top(), dec_.get_width(), dec_.get_height()))
        {
            dec();
            return true;
        }
    }
    return false;
};


bool NumericBox::MouseHover(int x, int y, Graphics &g) {
    if(!Control::lock_events_)
        return dec_.MouseHover(x, y, g) || inc_.MouseHover(x, y, g);
    return false;
}