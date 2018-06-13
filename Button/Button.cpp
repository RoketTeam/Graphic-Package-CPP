#include "Button.h"
#include <iostream>
#include "../IBorder/OneLine.h"

using namespace std;


Button::Button(string text): Label(text) {
    this->setBorder(new OneLine());
    isHover_ = false;
}

void Button::mousePressed(int x, int y, bool isLeft) {
    this->notify();
}

string Button::getText() {
    Label::getText();
}

void Button::draw(Graphics &g, int x, int y, size_t z) {
    Label::draw(g, x, y, z);
}

bool Button::mouseHover(int x, int y, Graphics &g){
    if(isInside(top_, left_, x, y, width_, height_)){
        hover();
        g.setBackground(Color::White, height_, left_, top_);
        return false;
    } else if (isHover()) {
        unHover();
        g.setBackground(Color::Black);
        return true;
    }
    return false;
}


Button::~Button() {
    delete this->border_;
}

