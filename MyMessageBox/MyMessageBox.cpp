#include "../IBorder/OneLine.h"
#include "../MyMessageBox/MyMessageBox.h"
#include <iostream>


void MyMessageBox::draw(Graphics& g, int x, int y, size_t z){
    if(is_visible && z == 3){
        Color background = g.getBackground();
        Color foreground = g.getForeground();
        if(background_ != Color::Transparent)
            g.setBackground(background_);
        if(foreground_ != Color::Transparent)
            g.setForeground(foreground_);
        width_ = ok_.getWidth() + cancel_.getWidth() + message_.getText().length();
        if(border_)
            border_->drawBorder(x, y, width_, g, getHeight());
        int center = width_ / 4 - 1;
        message_.draw(g, center, y, 0);
        ok_.draw(g, center + 1, y+3, 0);
        cancel_.draw(g, center + 7, y+3, 0);

        g.setBackground(background);
        g.setForeground(foreground);
    }
}

MyMessageBox::MyMessageBox(string message) :
        ok_("OK"),
        cancel_("CANCEL"),
        message_(message)
{
    setBorder(new OneLine());
    ok_.setBackground(Color::Green);
    cancel_.setBackground(Color::Red);

    height_ = message_.getHeight() + 4;
    width_ = ok_.getWidth() + cancel_.getWidth() + message_.getText().length();
    is_visible = true;
    ok_.add(this);
    cancel_.add(this);
}

bool MyMessageBox::mouseHover(int x, int y, Graphics &g) {
    return ok_.mouseHover(x, y, g) || cancel_.mouseHover(x, y, g);
}

void MyMessageBox::mousePressed(int x, int y, bool isLeft) {
    ok_.mousePressed(x, y, isLeft);
    cancel_.mousePressed(x, y, isLeft);
};

void MyMessageBox::action(IObservable *observable) {
    // TODO: Check who is pressed and handle it
    if(is_visible){
        is_visible = false;
        ok_.setClickable(false);
        cancel_.setClickable(false);
    }
    else {
        is_visible = true;
    }
}