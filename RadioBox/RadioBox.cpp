#include "../RadioBox/RadioBox.h"



bool RadioBox::MouseHover(int x, int y, Graphics &g) {
    bool redraw = false;
    for (auto list_item: items_){
        if(list_item->MouseHover(x, y, g))
            redraw = true;
    }
    return redraw;
}

void RadioBox::SwitchCheckedItem() {
    for (int i=0; i < items_.size(); ++i){
        ListItem* current_item = static_cast<ListItem*> (items_[i]);
        if(current_item->is_focus()){
            current_item->MarkAsChecked();
            DisselectOthers(i);
            return;
        }
    }
}

void RadioBox::MousePressed(int x, int y, bool isLeft){
    if(isLeft){
        SwitchCheckedItem();
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
void RadioBox::KeyDown(int keyCode, char character) {

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
        if(current_item)
            current_item->unfocus();
        if(index == list_size - 1) {
            temp = static_cast<ListItem*> (items_[0]);
            temp->focus();
        }
        else {
            temp = static_cast<ListItem*> (items_[index+1]);
            temp->focus();
        }
        return;
    }

    //Space key pressed
    if (keyCode == VK_SPACE || keyCode == VK_RETURN) {
        SwitchCheckedItem();
        return;
    }

    //Up key pressed
    if (keyCode == VK_UP) {
        if(current_item)
            current_item->unfocus();

        if(index == 0 || index == -1) {
            temp = static_cast<ListItem*> (items_[list_size - 1]);
            temp->focus();
        }
        else {
            temp = static_cast<ListItem*> (items_[index - 1]);
            temp->focus();
        }
        return;

    }

}
