#include "../RadioBox/RadioBox.h"

int RadioBox::switch_checked_item() {
    for (int i=0; i < items_.size(); ++i){
        ListItem* current_item = static_cast<ListItem*> (items_[i]);
        if(current_item->is_focus()){
            current_item->MarkAsChecked();
			unselec_others(i);
            return i;
        }
    }
	return -1;
}

void RadioBox::unselec_others(int selected) {
    for (int i=0; i < items_.size(); ++i) {
        if(i != selected){
            ListItem* current_item = static_cast<ListItem*> (items_[i]);
            current_item->MarkAsUnchecked();
        }
    }
}

int RadioBox::select() {
    return switch_checked_item();
}