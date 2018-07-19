#include <vector>
#include "../ListItem/ListItem.h"

#pragma once

using namespace std;


class GenericList: public Control{

public:

    GenericList();
    ~GenericList(){}

    // Event handlers
    virtual bool MousePressed(int x, int y, bool isLeft);
    virtual bool MouseHover(int x, int y, Graphics &g);
    virtual bool KeyDown(int keyCode, char character);
    virtual bool MoveDown(int index, ListItem* current_item);
    virtual bool MoveUp(int index, ListItem* current_item);


    // Methods
    void draw(Graphics& g, int x, int y, size_t z);
    virtual int select();
	//void focus();
    void unfocus();
    void get_all_controls(vector<Control*>* controls);
    bool RemoveSelectedItem(ListItem* item);
    bool add_selected_item(ListItem* item);
    vector<string> get_value();
    bool can_get_focus() { return false; };

protected:
    vector<ListItem*> items_;
};