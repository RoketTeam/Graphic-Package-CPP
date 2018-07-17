#include "../GenericList/GenericList.h"

GenericList::GenericList() {
    height_ = 0;
}

bool GenericList::MouseHover(int x, int y, Graphics &g) {
    if(!Control::lock_events_) {
        bool redraw = false;
        for (auto list_item: items_) {
            if (list_item->MouseHover(x, y, g)) {
                redraw = true;
            }
        }
        return redraw;
    }
    return false;
}


bool GenericList::MousePressed(int x, int y, bool isLeft){
    if(isLeft){
        if(select() == -1){
            return false;
        }
        return true;
    }
    return false;
}

void GenericList::get_all_controls(vector<Control*>* controls){
    for(auto list_item: items_)
        controls->push_back(list_item);
}


bool GenericList::add_selected_item(ListItem *item) {
    try{
        item->set_parent(this);
        items_.push_back(item);
        height_ += item->get_height();
        return true;
    } catch (...) {
        return false;
    }
}

bool GenericList::RemoveSelectedItem(ListItem *item) {
    for(int i = 0; i < items_.size(); i++){
        if(items_[i]->get_text() == item->get_text())
        {
            try{
                items_.erase(items_.begin()+i);
                height_ -= item->get_height();
                return true;
            } catch (...){
                return false;
            }
        }
    }
    return false;
}

int GenericList::select() {
    for (int i=0; i < items_.size(); ++i){
        ListItem* current_item = static_cast<ListItem*> (items_[i]);
        if(current_item->is_focus()){
            if(current_item->is_checked())
                current_item->MarkAsUnchecked();
            else{
                current_item->MarkAsChecked();
            }
            return i;
        }
    }
    return -1;
}

vector<string> GenericList::get_value(){
    vector<string> value;
    for (int i=0; i < items_.size(); ++i){
        ListItem* current_item = items_[i];
        if(current_item->is_checked())
            value.push_back(current_item->get_text());
    }
    return value;
}


void GenericList::draw(Graphics& g, int x, int y, size_t z){
    if(z == 0){
        auto background = g.getBackground();
        auto foreground = g.getForeground();
        if(background_ != Color::Transparent)
            g.setBackground(background_);
        if(foreground_ != Color::Transparent)
            g.setForeground(foreground_);
        height_ = 0;
        for (int i=0; i < items_.size(); ++i){
            items_[i]->draw(g, x, y + i, z);
            height_ += items_[i]->get_height();
        }
        g.setBackground(background);
        g.setForeground(foreground);
    }
}

void GenericList::MoveDown(int index, ListItem* current_item){
    ListItem* temp;
    int list_size = items_.size();

    if(current_item)
        current_item->unfocus();
    if(index == list_size - 1) {
        temp = static_cast<ListItem*> (items_[0]);
        set_focus(*temp);
    }
    else {
        temp = static_cast<ListItem*> (items_[index+1]);
        set_focus(*temp);
    }
    return;
}

void GenericList::MoveUp(int index, ListItem* current_item) {
    ListItem* temp;
    int list_size = items_.size();
    if(current_item)
        current_item->unfocus();

    if(index == 0 || index == -1) {
        temp = static_cast<ListItem*> (items_[list_size - 1]);
        set_focus(*temp);
    }
    else {
        temp = static_cast<ListItem*> (items_[index - 1]);
        set_focus(*temp);
    }
    return;
}


void GenericList::unfocus(){
    for (auto list_item: items_){
        list_item->unfocus();
    }
}


bool GenericList::KeyDown(int keyCode, char character) {

    ListItem* temp;
    ListItem* current_item = nullptr;
    int index = -1;
    int list_size = items_.size();
    for(int i=0 ; i<list_size ; ++i) {
        temp = static_cast<ListItem*> (items_[i]);
        if (temp->is_focus()){
            current_item = temp;
            index = i;
        }
    }
    if(!current_item){
        index = -1;
    }
    //Down key pressed
    if(keyCode == VK_DOWN) {
        MoveDown(index, current_item);
        return true;
    }
    //Space key pressed
	else if (keyCode == VK_SPACE || keyCode == VK_RETURN) {
        select();
        return true;
    }
    //Up key pressed
    else if (keyCode == VK_UP) {
        MoveUp(index, current_item);
        return true;
    }

    return false;

}
