#include "../IBorder/OneLine.h"
#include "../MyMessageBox/MyMessageBox.h"
#include <iostream>


MyMessageBox::MyMessageBox(string message) :
        ok_("OK"),
        cancel_("CANCEL"),
        message_(message)
{
    set_border(new OneLine());
    ok_.set_background(Color::Green);
    cancel_.set_background(Color::Red);

    height_ = message_.get_height() + 4;
    width_ = ok_.get_width() + cancel_.get_width() + message_.get_text().length();
    is_visible_ = true;
    ok_.add(this);
    cancel_.add(this);
}


void MyMessageBox::draw(Graphics& g, int x, int y, size_t z){
    if(is_visible_ && z == 3){
        auto background = g.getBackground();
        auto foreground = g.getForeground();
        if(background_ != Color::Transparent)
            g.setBackground(background_);
        if(foreground_ != Color::Transparent)
            g.setForeground(foreground_);
        width_ = ok_.get_width() + cancel_.get_width() + message_.get_text().length();
        border_->drawBorder(x, y, width_, g, get_height());
        int center = width_ / 4 - 1;
        message_.draw(g, center, y, 0);
        ok_.draw(g, center + 1, y+3, 0);
        cancel_.draw(g, center + 7, y+3, 0);

        g.setBackground(background);
        g.setForeground(foreground);
    }
}


bool MyMessageBox::MouseHover(int x, int y, Graphics &g) {
    return ok_.MouseHover(x, y, g) || cancel_.MouseHover(x, y, g);
}

void MyMessageBox::MousePressed(int x, int y, bool isLeft) {
    ok_.MousePressed(x, y, isLeft);
    cancel_.MousePressed(x, y, isLeft);
};

void MyMessageBox::action(IObservable *observable) {
    // TODO: Check who is pressed and handle it
    if(is_visible_){
        is_visible_ = false;
        ok_.set_clickable(false);
        cancel_.set_clickable(false);
    }
    else {
        is_visible_ = true;
    }
}