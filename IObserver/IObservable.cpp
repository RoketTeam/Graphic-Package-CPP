#include "IObservable.h"

using namespace std;


void IObservable::notify(){
    for (auto listener: listeners_){
        listener->action(this);
    }
}

void IObservable::add(IListener* listener){
    listeners_.push_back(listener);
}

IObservable::~IObservable() {}

