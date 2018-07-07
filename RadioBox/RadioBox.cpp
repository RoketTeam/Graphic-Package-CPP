#include "../RadioBox/RadioBox.h"



int RadioBox::SwitchCheckedItem() {
    for (int i=0; i < items_.size(); ++i){
        ListItem* current_item = static_cast<ListItem*> (items_[i]);
        if(current_item->is_focus()){
            current_item->MarkAsChecked();
            DisselectOthers(i);
            return i;
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

int RadioBox::select() {
    SwitchCheckedItem();
}