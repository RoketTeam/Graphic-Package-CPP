#include "NumericBox.h"
#include "../IBorder/OneLine.h"
#include <iostream>

using namespace std;


NumericBox::NumericBox(int minValue, int maxValue):
        minVal_(minValue),
        maxVal_(maxValue),
        inc_("+"),
        dec_("-"),
        value_(minValue),
        textValue_(to_string(minValue))
{
    inc_.add(this);
    dec_.add(this);
    this->setBackground(Color::Orange);
}

void NumericBox::setMaxValue(int value) {
    maxVal_ = value;
    if (value_ > maxVal_)
        value_ = maxVal_;
}

void NumericBox::setMinValue(int value) {
    minVal_ = value;
    if (value_ > minVal_)
        value_ = minVal_;
}

void NumericBox::setValue(int value) {
    if(value <= maxVal_ && value >= minVal_)
        value_ = value;
}


int NumericBox::getValue() {
    return value_;
}


void NumericBox::inc() {

    if (maxVal_ >= value_+1){
        value_ += 1;
        textValue_.setText(to_string(value_));
    }
}

void NumericBox::dec() {
    if (value_ - 1 >= minVal_) {
        value_ -= 1;
        textValue_.setText(to_string(value_));
    }
}

void NumericBox::action(IObservable* iObservable) {
    if(!(((Button*)iObservable)->getText().compare (" - "))){
        inc();
    } else if (!(((Button*)iObservable)->getText().compare(" + "))) {
        dec();
    }
}

void NumericBox::mousePressed(int x, int y, bool isLeft) {
    if(isInside(x, y, inc_.getLeft(), inc_.getTop(), inc_.getWidth(), inc_.getHeight()))
        inc();

    if(isInside(x, y, dec_.getLeft(), dec_.getTop(), dec_.getWidth(), dec_.getHeight()))
        dec();
};


void NumericBox::draw(Graphics& g, int x, int y, size_t z){
    if(!z){
        Color background = g.getBackground();
        Color foreground = g.getForeground();
        textValue_.setLeft(inc_.getWidth());
        dec_.setLeft(textValue_.getLeft() + textValue_.getText().length() + 2);
        if(background_ != Color::Transparent)
            g.setBackground(background_);
        if(foreground_ != Color::Transparent)
            g.setForeground(foreground_);
        this->fillBackground(x, y, dec_.getLeft(), g);
        inc_.draw(g, x, y, 0);
        textValue_.draw(g, textValue_.getLeft(), y, 0);
        dec_.draw(g, dec_.getLeft(), 0, 0);
        g.setBackground(background);
        g.setForeground(foreground);
    }
}


bool NumericBox::mouseHover(int x, int y, Graphics &g) {
    return dec_.mouseHover(x, y, g) || inc_.mouseHover(x, y, g);
}