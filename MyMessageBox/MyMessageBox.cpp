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
        if(border_)
            border_->drawBorder(left_, top_, width_, g, getHeight());
        message_.draw(g, x+1, y+1, 0);
        ok_.draw(g, x+2, y+3, 0);
        cancel_.draw(g, x+10, y+3, 0);

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
    setBackground(Color::Purple);
    ok_.setBackground(Color::Green);
    cancel_.setBackground(Color::Red);

    height_ = message_.getHeight() + 4;
    width_ = message_.getText().length() + 4;
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
    if(is_visible)
        is_visible = false;
    else
        is_visible = true;
}