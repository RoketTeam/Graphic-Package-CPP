#include "../IBorder/OneLine.h"
#include "../MyMessageBox/MyMessageBox.h"
#include <iostream>


MyMessageBox::MyMessageBox(string message) :
        ok_("OK"),
        cancel_("CANCEL"),
        value_(""),
        message_(message)
{
    set_border(new OneLine());
    ok_.set_background(Color::Green);
    cancel_.set_background(Color::Red);
    background_ = Color::Blue;
    foreground_ = Color::Transparent;
    height_ = message_.get_height() + 4;
    width_ = ok_.get_width() + cancel_.get_width() + message_.get_text().length();
    is_visible_ = true;
    ok_.add(this);
    cancel_.add(this);

    set_margin(0);
    set_margin_left(0);
}


void MyMessageBox::draw(Graphics& g, int x, int y, size_t z){
    if(is_visible_ && z == 3){
        Control::lock_events();
        x = 1;
        y = 4;
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
        g.setCursorVisibility(false);
    } else if(!is_visible_){
        Control::enable_events();
    }
}


bool MyMessageBox::MouseHover(int x, int y, Graphics &g) {
    return ok_.MouseHover(x, y, g) || cancel_.MouseHover(x, y, g);
}

void MyMessageBox::MousePressed(int x, int y, bool isLeft) {
    ok_.MousePressed(x, y, isLeft);
    cancel_.MousePressed(x, y, isLeft);
};

void MyMessageBox::ok_pressed(){
    value_ = "OK";
}

void MyMessageBox::cancel_pressed(){
    value_ = "CANCEL";
}

void MyMessageBox::action(IObservable *observable) {
    if(is_visible_){
        is_visible_ = false;
        ok_.set_clickable(false);
        cancel_.set_clickable(false);
        Button* pressed_button = static_cast<Button*> (observable);
        if(pressed_button && !ok_.get_text().compare(pressed_button->get_text())){
            ok_pressed();
        } else if (pressed_button && !cancel_.get_text().compare(pressed_button->get_text())) {
            cancel_pressed();
        }
        enable_events();
        notify();
    }
    else {
        is_visible_ = true;
        lock_events();
    }


}