#include "../IComposite/IComposite.h"


void IComposite::Add(Control *item) {
    items_.push_back(item);
}

Control* IComposite::GetItem(int index) {
    if (items_.size() < index){
        return nullptr;
    }

    return items_[index];
}

IComposite::~IComposite() {}