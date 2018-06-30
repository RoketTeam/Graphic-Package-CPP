
#include "../ListItem/ListItem.h"



ListItem::ListItem(string description):
        description_label_(description),
        is_focused_(false),
        is_checked_(false)
{
    line_length_ = description.length();
    set_background(Color::Transparent);
    set_foreground(Color::Green);
}

void ListItem::focus() {
    is_focused_ = true;
    Color temp = background_;
    background_ = foreground_;
    foreground_ = temp;
}

void ListItem::unfocus() {
    is_focused_ = false;
    Color temp = background_;
    background_ = foreground_;
    foreground_ = temp;
}

bool ListItem::MouseHover(int x, int y, Graphics &g){
    bool redraw = false;
    if (isInside(x-1, y-1, top_, left_, width_, height_)){
        if(!is_focused_){
            focus();
            redraw = true;
        }
    }
    else if (is_focused_) {
        unfocus();
        redraw = true;
    }
    return redraw;
}

void ListItem::MousePressed(int x, int y, bool isLeft) {
    if (is_checked_)
        is_checked_ = false;
    else
        is_checked_ = true;
}

void ListItem::draw(Graphics &g, int x, int y, size_t z) {
    if (z == 0) {
        top_ = y;
        left_ = x;
        width_ = description_label_.get_text().length() + 6;
        height_ = 1;
        Color background = g.getBackground();
        Color foreground = g.getForeground();
        if(background_ != Color::Transparent)
            g.setBackground(background_);
        if(foreground_ != Color::Transparent)
            g.setForeground(foreground_);
        border_->drawBorder(x, y, width_ - 2, g);
        string line;
        if (is_checked_)
            line = "[X] " + description_label_.get_text();
        else
            line = "[ ] " + description_label_.get_text();
        g.write(x+ 1, y + 1, line);
        g.setBackground(background);
        g.setForeground(foreground);
    }
}


