#include "../IComposite/IComposite.h"
#include "../ListItem/ListItem.h"

#pragma once

using namespace std;


class GenericList : public IComposite {

public:

    GenericList();
    ~GenericList(){}

    // Event handlers
    void MousePressed(int x, int y, bool isLeft);
    bool MouseHover(int x, int y, Graphics &g);
    void KeyDown(int keyCode, char character);
    void MoveDown(int index, ListItem* current_item);
    void MoveUp(int index, ListItem* current_item);
    void draw(Graphics& g, int x, int y, size_t z);
    void action(IObservable* observable){}
    virtual int select();


private:
    int selected_index_;
};