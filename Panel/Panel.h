#include "../IComposite/IComposite.h"

#pragma once

using namespace std;


class Panel : public IComposite {

private:
	int focus_control_index;

public:

	// methods
	Panel();
    static Control* getFocus();
    static void setFocus(Control& control);
    void draw(Graphics& g, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft);
    bool mouseHover(int x, int y, Graphics &g);
    void keyDown(int keyCode, char character);
    void getAllControls(vector<Control*>* controls);
    void action(IObservable* observable){};
    void calculateHeight();
    void calculateWidth();
    //D'tors
	 ~Panel() {};

};