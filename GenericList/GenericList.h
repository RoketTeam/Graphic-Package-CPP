#include <vector>
#include "../ListItem/ListItem.h"

#pragma once

using namespace std;


class GenericList: public Control{

public:

    GenericList();
    ~GenericList(){}

    // Event handlers
    virtual void MousePressed(int x, int y, bool isLeft);
    virtual bool MouseHover(int x, int y, Graphics &g);
    virtual void KeyDown(int keyCode, char character);
    virtual void MoveDown(int index, ListItem* current_item);
    virtual void MoveUp(int index, ListItem* current_item);


    // Methods
    void draw(Graphics& g, int x, int y, size_t z);
    virtual int select();
    void unfocus();
    void get_all_controls(vector<Control*>* controls);
    bool RemoveSelectedItem(ListItem* item);
    bool AddSelectedItem(ListItem* item);
    vector<string> get_value();
    bool CanGetFocus() { return true; };

protected:
    vector<ListItem*> items_;
};