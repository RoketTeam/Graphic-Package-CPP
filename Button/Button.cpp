#include "Button.h"
#include <iostream>
#include "../IBorder/OneLine.h"
#include "../IBorder/DoubleLine.h"

using namespace std;


Button::Button(string text): Label(text) {
    this->setBorder(new OneLine());
    isHover_ = false;
    this->setBackground(Color::Transparent);
}

void Button::mousePressed(int x, int y, bool isLeft) {
    this->notify();
}

string Button::getText() {
    return Label::getText();
}

void Button::draw(Graphics &g, int x, int y, size_t z) {
    Label::draw(g, x, y, z);
}

bool Button::mouseHover(int x, int y, Graphics &g){
    if(isInside(x, y, left_, top_, width_, height_)){
        if(isHover_)
            return false;
        hover();
        this->setBorder(new DoubleLine());
        return true;
    } else if (isHover()) {
        unHover();
        this->setBorder(new OneLine());
        return true;
    }
    return false;
}


Button::~Button() {
    delete this->border_;
}

