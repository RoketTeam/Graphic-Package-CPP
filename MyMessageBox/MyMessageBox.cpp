#include "../IBorder/OneLine.h"
#include "../MyMessageBox/MyMessageBox.h"
#include <iostream>


void MyMessageBox::draw(Graphics& g, int x, int y, size_t z){
    if(z == 3){
        if(border_)
            border_->drawBorder(left_, top_, width_, g, getHeight());
        Color background = g.getBackground();
        Color foreground = g.getForeground();
        if(background_ != Color::Transparent)
            g.setBackground(background_);
        if(foreground_ != Color::Transparent)
            g.setForeground(foreground_);
        g.setBackground(background);
        g.setForeground(foreground);
    }
}

MyMessageBox::MyMessageBox(string message) :
        ok_("OK"),
        cancel_("CANCEL"),
        message_(message)
{
    this->setBorder(new OneLine());
    this->setBackground(Color::Transparent);
    this->height_ = 5;
    this->width_ = 5;
}
