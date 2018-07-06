#include <vector>
#include "../ListItem/ListItem.h"

#pragma once

using namespace std;


class GenericList: public Control{

public:

    GenericList();
    ~GenericList(){}

    // Event handlers
    void MousePressed(int x, int y, bool isLeft);
    bool MouseHover(int x, int y, Graphics &g);
    void KeyDown(int keyCode, char character);
    void MoveDown(int index, ListItem* current_item);
    void MoveUp(int index, ListItem* current_item);
    // Methods
    void draw(Graphics& g, int x, int y, size_t z);
    virtual int select();
    bool RemoveSelectedItem(ListItem* item);
    bool AddSelectedItem(ListItem* item);
    vector<string> get_value();


protected:
    vector<ListItem*> items_;
};