#include "Button.h"
#include <iostream>



Button::Button(string text): Label(text) {}

void Button::mousePressed(int x, int y, bool isLeft) {
    notify();
}

void Button::notify(){
    for (auto listener: listeners_){
        listener->action();
    }
}

Button::~Button() {}