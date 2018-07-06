#include "../IComposite/IComposite.h"


bool IComposite::Add(Control *item) {
    try{
        items_.push_back(item);
    } catch (...){
        return false;
    }
    return true;
}

Control* IComposite::GetItem(int index) {
    if (items_.size() < index){
        return nullptr;
    }

    return items_[index];
}


IComposite::~IComposite() {}