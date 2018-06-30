#include "../RadioBox/RadioBox.h"



bool RadioBox::MouseHover(int x, int y, Graphics &g) {
    bool redraw = false;
    for (auto list_item: items_){
        if(list_item->MouseHover(x, y, g))
            redraw = true;
    }
    return redraw;
}

void RadioBox::MousePressed(int x, int y, bool isLeft){
    if(isLeft){
        for (int i=0; i < items_.size(); ++i){
            ListItem* current_item = static_cast<ListItem*> (items_[i]);
            if(current_item->is_focus()){
                current_item->MarkAsChecked();
                DisselectOthers(i);
                return;
            }
        }
    }
}

void RadioBox::DisselectOthers(int selected) {
    for (int i=0; i < items_.size(); ++i) {
        if(i != selected){
            ListItem* current_item = static_cast<ListItem*> (items_[i]);
            current_item->MarkAsUnchecked();
        }
    }
}

void RadioBox::draw(Graphics& g, int x, int y, size_t z){
    if(z == 0){
        for (int i=0; i < items_.size(); ++i){
            items_[i]->draw(g, x, y + i, z);
        }
    }
}
