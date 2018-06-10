#include "Button.h"
#include <iostream>

using namespace std;


Button::Button(string text): Label(text) {}

void Button::mousePressed(int x, int y, bool isLeft) {
    notify();
}

string Button::getText() {
    Label::getText();
}


Button::~Button() {}

