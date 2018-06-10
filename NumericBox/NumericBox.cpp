#include "NumericBox.h"
#include <iostream>

using namespace std;


NumericBox::NumericBox(int minValue, int MaxValue):
        minVal_(minValue),
        maxVal_(minValue),
        inc_("INC"),
        dec_("DEC"),
        value_(minValue),
        textValue_(to_string(minValue)){}

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
    if (value_ + 1 < maxVal_){
        value_ += 1;
        // redraw
    }
}

void NumericBox::dec() {
    if (value_ - 1 > minVal_) {
        value_ -= 1;
        // redraw
    }
}

void NumericBox::action(IObservable* iObservable) {
    if(!(((Button*)iObservable)->getText().compare ("INC"))){
        inc();
    } else if (!(((Button*)iObservable)->getText().compare("DEC"))) {
        dec();
    }
}