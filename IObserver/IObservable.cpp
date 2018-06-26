#include "IObservable.h"

using namespace std;


void IObservable::notify(){
    for (auto listener: listeners_){
        listener->action(this);
    }

    for(auto function: event_listeners){
        function();
    }
}

void IObservable::add(IListener* listener){
    listeners_.push_back(listener);
}

void IObservable::addEventListener(void (*function)() ) {
    event_listeners.push_back(function);
}
IObservable::~IObservable() {}

