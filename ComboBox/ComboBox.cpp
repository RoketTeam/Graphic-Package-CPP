#include "../ComboBox/ComboBox.h"

ComboBox::ComboBox():toggle_list_("V"){
    ListItem* default_item = new ListItem("Choose an item from the list");
    default_item->CanGetFocus(false);
    default_item->set_clickable(false);
    default_item->set_checked_bullet_symbol("");
    default_item->set_unchecked_bullet_symbol("");
    AddSelectedItem(default_item);
    toggle_list_.add(this);
    height_ = 3;
    width_ = default_item->get_text().length() + 6;
    selected_index_ = 0;
    is_open_  = false;
    set_margin(0);
    set_margin_left(0);
}

bool ComboBox::AddSelectedItem(ListItem* item){
    item->CanGetFocus(false);
    return RadioBox::AddSelectedItem(item);
}


void ComboBox::CalculateHeight() {
    height_ = 3;
    if(is_open()){
        for(int i = 0; i < items_.size(); i ++){
            auto item = items_[i];
            height_ += (3 + items_[i]->get_margin());
        }
    }

}

void ComboBox::CalculateWidth() {
    width_ = 0;
    for(int i = 0; i < items_.size(); i ++){
        int item_width = items_[i]->get_width();
        if( item_width> width_)
            width_ = item_width;
    }
}

void ComboBox::draw(Graphics& g, int x, int y, size_t z){
    if(z == 2){
        top_ = y;
        left_ = x;
        auto background = g.getBackground();
        auto foreground = g.getForeground();
        if(background_ != Color::Transparent)
            g.setBackground(background_);
        if(foreground_ != Color::Transparent)
            g.setForeground(foreground_);
        set_border(new OneLine);
        border_->drawBorder(x, y, width_, g, 3);
        if(is_open()){
            toggle_list_.set_text("^");
            toggle_list_.draw(g, x, y, 0);
            items_[0]->draw(g, x + toggle_list_.get_width(), y, z);
            for (int i=1; i < items_.size(); ++i){
                auto item = items_[i];
                item->set_unchecked_bullet_symbol("");
                item->set_checked_bullet_symbol("");
                item->set_clickable(true);
                item->set_width(items_[0]->get_width());
                item->set_border(new OneLine);
                item->draw(g, x + toggle_list_.get_width() - 1, y + i*3, 0);
            }

        } else{
            toggle_list_.set_text("v");
            toggle_list_.draw(g, x, y, 0);
            items_[selected_index_]->unfocus();
            items_[selected_index_]->draw(g, x + toggle_list_.get_width(), y, 0);
            for (int i=1; i < items_.size(); ++i){
                items_[i]->set_clickable(false);
            }
        }
        g.setBackground(background);
        g.setForeground(foreground);
    }
}

string ComboBox::get_value(){
    return items_[selected_index_]->get_text();
}


void ComboBox::action(IObservable* observable){
    if(is_open()){
        close();
    } else {
        open();
    }
}


bool ComboBox::MousePressed(int x, int y, bool isLeft) {
    CalculateHeight();
    if(isInside(x, y, left_, top_, width_, height_)){
        if(is_open()){
            for(int i=0; i< items_.size(); ++i)
                if(items_[i]->is_focus())
                    selected_index_ = i;
            close();
            CalculateHeight();
            return true;
        }
        else {
            open();
            set_focus(*this);
            return true;
        }

    } else if (is_open()){
        close();
        CalculateHeight();
        return true;
    }
    return false;

};

bool ComboBox::KeyDown(int keyCode, char character) {
    if (is_open()){
        //Space or Return key pressed
        if (keyCode == VK_SPACE || keyCode == VK_RETURN) {
            for(int i=0; i< items_.size(); ++i)
                if(items_[i]->is_focus())
                    selected_index_ = i;
            close();
            CalculateHeight();
            return true;
        }
        else
            return GenericList::KeyDown(keyCode, character);
    } else
        return false;
}
