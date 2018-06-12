#include "Button.h"
#include <iostream>
#include "../IBorder/OneLine.h"

using namespace std;


Button::Button(string text): Label(text) {
    this->setBorder(new OneLine());
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


Button::~Button() {
    delete this->border_;
}

