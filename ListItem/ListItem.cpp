
#include "../ListItem/ListItem.h"



ListItem::ListItem(string description):
        description_label_(description),
        is_focused_(false),
        is_checked_(false)
{
    line_length_ = description.length();
    height_ = 1;
    border_ = new NoneBorder();
    foreground_ = Color::White;
    checked_bullet_symbol_ = "[X] ";
    unchecked_bullet_symbol_ = "[ ] ";
    parent_ = nullptr;
    is_clickable_ = true;
}

void ListItem::focus() {
    if(!is_focused_ && is_clickable_){
        is_focused_ = true;
        Color temp = background_;
        background_ = foreground_;
        foreground_ = temp;
    }
}

void ListItem::unfocus() {
    if(is_focused_ && is_clickable_){
        Color temp = background_;
        background_ = foreground_;
        foreground_ = temp;
        is_focused_ = false;
        set_focus(*parent_);
    }
}

bool ListItem::MouseHover(int x, int y, Graphics &g){
    bool redraw = false;
    if (isInside(x-1, y - 1, left_, top_, width_, height_)){
        if(!is_focused_ && is_clickable_){
            focus();
            redraw = true;
        } else {
            redraw = false;
        }
    }
    else if (is_focused_) {
        unfocus();
        redraw = true;
    }
    return redraw;
}

bool ListItem::MousePressed(int x, int y, bool isLeft) {
    if (is_checked_ && is_clickable_)
        MarkAsUnchecked();
    else
        MarkAsChecked();
	return true;
}

void ListItem::draw(Graphics &g, int x, int y, size_t z) {
    top_ = y;
    left_ = x;
    auto temp_width = description_label_.get_text().length() + 6;
    if(width_ < temp_width)
        width_ = temp_width;
    height_ = 1;
    auto background = g.getBackground();
    auto foreground = g.getForeground();
    if(background_ != Color::Transparent)
        g.setBackground(background_);
    else
        background_ = background;
    if(foreground_ != Color::Transparent)
        g.setForeground(foreground_);
    else
        foreground_ = foreground;
    border_->drawBorder(x, y, width_ - 2, g);
    string line;
    if (is_checked_)
        line = checked_bullet_symbol_ + description_label_.get_text();
    else
        line = unchecked_bullet_symbol_ + description_label_.get_text();
    g.write(x+ 1, y + 1, line);
    g.setBackground(background);
    g.setForeground(foreground);

}

void ListItem::MarkAsUnchecked(){
    is_checked_ = false;
}

void ListItem::MarkAsChecked(){
    is_checked_ = true;
}

bool ListItem::KeyDown(int keyCode, char character){
    if (!parent_ && (keyCode == VK_SPACE || keyCode == VK_RETURN)) {
        if(is_checked())
            MarkAsUnchecked();
        else
            MarkAsChecked();
		return true;
    }
    else
        return parent_->KeyDown(keyCode, character);
}

