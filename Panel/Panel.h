#pragma once

#include "../Label/Label.h"
#include "../Button/Button.h"
#include "../NumericBox/NumericBox.h"
#include "../IBorder/OneLine.h"
#include "../IBorder/DoubleLine.h"
#include "../MyMessageBox/MyMessageBox.h"
#include "../IComposite/IComposite.h"
#include "../ListItem/ListItem.h"
#include "../RadioBox/RadioBox.h"
#include "../GenericList/GenericList.h"
#include "../CheckList/CheckList.h"
#include "../TextBox/TextBox.h"
#include "../ComboBox/ComboBox.h"

using namespace std;


class Panel : public IComposite {


    public:

        // C'tor & D'tor
        Panel();
        ~Panel() {};

        // Setters & Getters
        void set_focus(Control& control){Control::set_focus(control);}
        Control* get_focus(){ return items_[focus_control_index_];}
        void get_all_controls(vector<Control*>* controls);

        // Methods
        void draw(Graphics& g, int x, int y, size_t z);
        bool Add(Control* item);


    // Event handler
        bool MousePressed(int x, int y, bool isLeft);
        bool MouseHover(int x, int y, Graphics &g);
        bool KeyDown(int keyCode, char character);
        void action(IObservable* observable);
        void CalculateHeight();
        void CalculateWidth();



    private:
        int focus_control_index_;

};