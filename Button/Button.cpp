#include "Button.h"
#include <iostream>

using namespace std;


Button::Button(string text): Label(text) {}

void Button::mousePressed(int x, int y, bool isLeft) {
    this->notify();
}

string Button::getText() {
    Label::getText();
}

void Button::draw(Graphics &g, int x, int y, size_t z) {

}


Button::~Button() {}

