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

using namespace std;


class Panel : public IComposite {


    public:

        // C'tor & D'tor
        Panel();
        ~Panel() {};

        // Setters & Getters
        static void set_focus(Control& control);
        static Control* get_focus();
        void get_all_controls(vector<Control*>* controls);

        // Methods
        void draw(Graphics& g, int x, int y, size_t z);

        // Event handler
        void MousePressed(int x, int y, bool isLeft);
        bool MouseHover(int x, int y, Graphics &g);
        void KeyDown(int keyCode, char character);
        void action(IObservable* observable){};
        void CalculateHeight();
        void CalculateWidth();



    private:
        int focus_control_index_;

};