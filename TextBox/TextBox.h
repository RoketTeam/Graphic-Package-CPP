#pragma once

#include <string>
#include "../Control/Control.h"
#include "../Label/Label.h"
#include "../IObserver/IObservable.h"

using namespace std;

class TextBox : public Control
{
private:
	int length_;
	int highlight_index_;
	Label value_;

	void set_highlight(int index);

public:
	// C'tors & D'tors
	TextBox();
	TextBox(short left, short top, int length);
	TextBox(short left, short top, int length, string value);
	~TextBox() {};

	// Setters & Getters
	void set_left(short left);
	void set_top(short top);
	void set_frame_size(int length);
	void get_all_controls(vector<Control*>* controls);
	void set_focus(Control& control);

	// methods
	void add_char(int x, char ch);
	void delete_char();
	void delete_all_text();
	void draw(Graphics& g, int x, int y, size_t z);
	bool CanGetFocus() { return TRUE; };

	//Handler
	void KeyDown(int keyCode, char character);
	void MousePressed(int x, int y, bool isLeft);
	bool MouseHover(int x, int y, Graphics &g);




};

