#include "Button.h"
#include <iostream>
#include "../IBorder/OneLine.h"
#include "../IBorder/DoubleLine.h"

using namespace std;


Button::Button(string text):
        Label(text)
{
    set_border(new OneLine());
    is_hover_ = false;
    set_background(Color::Transparent);
    set_clickable(true);
}

void Button::MousePressed(int x, int y, bool isLeft) {
    if(is_clickable())
        if(isLeft && isInside(x, y, get_left(), get_top(), get_width(), get_height()))
            notify();
}

string Button::get_text() {
    return Label::get_text();
}

void Button::draw(Graphics &g, int x, int y, size_t z) {
    Label::draw(g, x, y, z);
}

bool Button::MouseHover(int x, int y, Graphics &g){
    if(is_clickable()){
        if(isInside(x, y, get_left(), get_top(), get_width(), get_height())){
            if(is_hover_)
                return false;
            hover();
            set_border(new DoubleLine());
            return true;
        } else if (is_hover()) {
            unhover();
            set_border(new OneLine());
            return true;
        }
        return false;
    }
    return false;
}


Button::~Button() {
    delete border_;
}

